/**
* The MIT License (MIT)
*
* Copyright (c) 2018 Vladimir Mikhailov <beykerykt@gmail.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "stdafx.h"
#include "4_RollingText.h"
#include "iostream"

// Names
#define ClazzName "4_RollingText"
#define MW "Main Window"

// Global params
HINSTANCE hInst;
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	WNDCLASS wcex = { 0 };

	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.lpszClassName = ClazzName;
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClass(&wcex))
		return 0;

	HMENU hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDC_MY4_ROLLINGTEXT)); // загрузing менu from ресурсов
	HWND  mainWindow = CreateWindow(wcex.lpszClassName, MW, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, hMenu, hInstance, NULL);

	if (mainWindow == NULL)
		return 0;

	ShowWindow(mainWindow, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
	return 0;
}

/*
* Source: https://www.codeproject.com/Articles/740/Simple-Text-Rotation
*/
void DrawRotatedText(HDC hdc, char *str, LPRECT rect,
	double angle, UINT nOptions = 0)
{
	// convert angle to radian
	double pi = 3.141592654;
	double radian = pi * 2 / 360 * angle;

	// get the center of a not-rotated text
	SIZE TextSize;
	GetTextExtentPoint32(hdc, str, strlen(str), &TextSize); //вычисляет ширину и высоту заданной строки текста.

	POINT center;
	center.x = TextSize.cx / 2;
	center.y = TextSize.cy / 2;

	// now calculate the center of the rotated text
	POINT rcenter;
	rcenter.x = long(cos(radian) * center.x - sin(radian) * center.y);
	rcenter.y = long(sin(radian) * center.x + cos(radian) * center.y);

	// finally draw the text and move it to the center of the rectangle
	SetTextAlign(hdc, TA_BASELINE);
	SetBkMode(hdc, TRANSPARENT);
	ExtTextOut(hdc, rect->left + (rect->right - rect->left) / 2 - rcenter.x,
		rect->top + (rect->bottom - rect->top) / 2 + rcenter.y,
		nOptions, rect, str, strlen(str), NULL);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_CREATE:
		EnableMenuItem(GetMenu(hWnd), IDM_START, MF_DISABLED);
		SetTimer(hWnd, 0, 1000, NULL); // Запуск таймера на 1 секунду (1000 мс)
		break;
	case WM_TIMER: { // Событие которое вызывается таймером
					   InvalidateRect(hWnd, NULL, true);
					   double old_angle = (double)GetWindowLong(hWnd, GWL_USERDATA);
					   double next_angle = 10; // 10 градусов
					   double new_angle = old_angle + next_angle;
					   if (new_angle >= 360){
						   new_angle = 0;
					   }
					   SetWindowLong(hWnd, GWL_USERDATA, (LONG) new_angle);
	}
		break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_PAINT: {
					   PAINTSTRUCT ps;
					   HDC hdc = ::BeginPaint(hWnd, &ps);
					   RECT rc;
					   GetClientRect(hWnd, &rc);
					   HANDLE hfnt, hfntPrev;

					   // create font
					   LOGFONT lf;
					   ZeroMemory(&lf, sizeof(LOGFONT)); //clean memory for logfont
					   double angle = (double)GetWindowLong(hWnd, GWL_USERDATA);
					   lf.lfHeight = 30;
					   lf.lfWeight = FW_NORMAL;
					   lf.lfEscapement = angle * 10; // Для винды необходимо увеличить угол в 10 раз
					   lf.lfOrientation = angle * 10;
					   hfnt = CreateFontIndirect(&lf);
					   hfntPrev = SelectObject(hdc, hfnt);

					   //start drawning
					   TCHAR* str = TEXT("[SAMPLE TEXT]");
					   DrawRotatedText(hdc, str, &rc, angle);

					   SelectObject(hdc, hfntPrev);
					   DeleteObject(hfnt);

					   SetBkMode(hdc, OPAQUE);
					   ::EndPaint(hWnd, &ps);
	}
		break;
	case WM_COMMAND: // Команды из меню
	{
					   switch (wParam)
					   {
					   case IDM_EXIT:
						   KillTimer(hWnd, 0);
						   PostQuitMessage(0);
						   break;
					   case IDM_STOP:
						   if (KillTimer(hWnd, 0)){ // Хз, нужна ли это проверка или нет
							   EnableMenuItem(GetMenu(hWnd), IDM_STOP, MF_DISABLED);
							   EnableMenuItem(GetMenu(hWnd), IDM_START, MF_ENABLED);
						   }
						   break;
					   case IDM_START:
						   if (SetTimer(hWnd, 0, 1000, NULL)){ // Запуск таймера на 1 секунду (1000 мс)
							   EnableMenuItem(GetMenu(hWnd), IDM_START, MF_DISABLED);
							   EnableMenuItem(GetMenu(hWnd), IDM_STOP, MF_ENABLED);
						   }
						   break;
					   default:
						   return DefWindowProc(hWnd, message, wParam, lParam);
					   }
	}
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 0);
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
