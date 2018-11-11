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

	int CX = (GetSystemMetrics(SM_CXSCREEN));
	int CY = (GetSystemMetrics(SM_CYSCREEN));
	int X = CX / 5;
	int Y = CY / 5;

	HMENU hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDC_MY4_ROLLINGTEXT));
	HWND  mainWindow = CreateWindow(wcex.lpszClassName, MW, WS_OVERLAPPEDWINDOW,
		X, Y, CX - X * 2, CY - 2 * Y, NULL, hMenu, hInstance, NULL);

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_CREATE:
		if (SetTimer(hWnd, 0, 500, NULL)){
			EnableMenuItem(GetMenu(hWnd), IDM_START, MF_DISABLED);
		}
		SetWindowLong(hWnd, GWL_USERDATA, MAKELPARAM(0, 20));
		break;
	case WM_TIMER: {
					   LPARAM lparam = (LPARAM) GetWindowLong(hWnd, GWL_USERDATA);
					   double old_angle = (double) LOWORD(lparam);
					   double next_angle = 10;
					   double new_angle = old_angle + next_angle;
					   if (new_angle >= 360){
						   new_angle -= 360;
					   }
					   lparam = MAKELPARAM(new_angle, HIWORD(lparam));
					   SetWindowLong(hWnd, GWL_USERDATA, (LONG) lparam);
					   InvalidateRect(hWnd, NULL, true);
	}
		break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		return 0;
	case WM_LBUTTONDOWN: {
							 LPARAM lparam = (LPARAM) GetWindowLong(hWnd, GWL_USERDATA);
							 int font_size = (int) HIWORD(lparam);
							 font_size += 10;
							 lparam = MAKELPARAM(LOWORD(lparam), font_size);
							 SetWindowLong(hWnd, GWL_USERDATA, (LONG) lparam);
							 InvalidateRect(hWnd, NULL, true);
	}
		break;
	case WM_RBUTTONDOWN: {
							 LPARAM lparam = (LPARAM) GetWindowLong(hWnd, GWL_USERDATA);
							 int font_size = (int) HIWORD(lparam);
							 font_size -= 10;
							 if (font_size <= 0){
								 font_size = 1;
							 }
							 lparam = MAKELPARAM(LOWORD(lparam), font_size);
							 SetWindowLong(hWnd, GWL_USERDATA, (LONG) lparam);
							 InvalidateRect(hWnd, NULL, true);
	}
		break;
	case WM_PAINT: {
					   // Default
					   PAINTSTRUCT ps;
					   HDC hdc = ::BeginPaint(hWnd, &ps);
					   RECT rc;
					   GetClientRect(hWnd, &rc);

					   // create font
					   HANDLE hfnt, hfntPrev;
					   LOGFONT lf;
					   ZeroMemory(&lf, sizeof(LOGFONT)); //clean memory for logicfont
					   LPARAM lparam = (LPARAM) GetWindowLong(hWnd, GWL_USERDATA);
					   double angle = (double) LOWORD(lparam);
					   int font_size = (int) HIWORD(lparam);
					   lf.lfHeight = font_size;
					   lf.lfWeight = FW_NORMAL;
					   lf.lfEscapement = (long) angle * 10;
					   lf.lfOrientation = (long) angle * 10;
					   strcpy_s(lf.lfFaceName, "Times New Roman");
					   hfnt = CreateFontIndirect(&lf);
					   hfntPrev = SelectObject(hdc, hfnt);

					   // start drawning
					   TCHAR* str = TEXT("[SAMPLE TEXT]");
					   SetBkMode(hdc, TRANSPARENT);
					   SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
					   int x = (rc.right - rc.left) / 2;
					   int y = (rc.bottom - rc.top) / 2;
					   TextOut(hdc, x, y, str, strlen(str));

					   // Drop all
					   SetBkMode(hdc, OPAQUE);
					   SelectObject(hdc, hfntPrev);
					   DeleteObject(hfnt);
					   ::EndPaint(hWnd, &ps);
	}
		break;
	case WM_COMMAND:
	{
					   switch (wParam)
					   {
					   case IDM_EXIT:
						   KillTimer(hWnd, 0);
						   PostQuitMessage(0);
						   break;
					   case IDM_STOP:
						   if (KillTimer(hWnd, 0)){
							   EnableMenuItem(GetMenu(hWnd), IDM_STOP, MF_DISABLED);
							   EnableMenuItem(GetMenu(hWnd), IDM_START, MF_ENABLED);
						   }
						   break;
					   case IDM_START:
						   if (SetTimer(hWnd, 0, 500, NULL)){
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
