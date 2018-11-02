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
#include "2_4Panels.h"
#include "iostream"

// Names
#define ClazzName "2_4Panels"
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

	HWND  mainWindow = CreateWindow(wcex.lpszClassName, MW, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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

BOOL drawLine(HDC hdc, int x_min, int y_min, int x_max, int y_max) {
	MoveToEx(hdc, x_min, y_min, NULL);
	return LineTo(hdc, x_max, y_max);
}

void drawRect(HDC hdc, int side, int size_x, int size_y){
	RECT r;

	int line_pixel = 1;
	int half_x_l = (size_x / 2) + line_pixel;
	int half_x_r = (size_x / 2) - line_pixel;
	int half_y_t = (size_y / 2) + line_pixel;
	int half_y_b = (size_y / 2) - line_pixel;

	switch (side){
	case 1:
		r.top = 0;
		r.left = 0;
		r.right = half_x_r;
		r.bottom = half_y_b;
		break;
	case 2:
		r.top = 0;
		r.left = half_x_l;
		r.right = size_x;
		r.bottom = half_y_b;
		break;
	case 3:
		r.top = half_y_t;
		r.left = 0;
		r.right = half_x_r;
		r.bottom = size_y;
		break;
	case 4:
		r.top = half_y_t;
		r.left = half_x_l;
		r.right = size_x;
		r.bottom = size_y;
		break;
	default:
		break;
	}

	HBRUSH brush = HBRUSH(CreateSolidBrush(RGB(224, 224, 224)));
	FillRect(hdc, &r, brush);
	DeleteObject(brush);
}

int getRECTSide(int size_x, int size_y, POINT mouse_p){
	int mouse_x = mouse_p.x;
	int mouse_y = mouse_p.y;

	int line_pixel = 1;
	int half_x_l = (size_x / 2) + line_pixel;
	int half_x_r = (size_x / 2) - line_pixel;
	int half_y_t = (size_y / 2) + line_pixel;
	int half_y_b = (size_y / 2) - line_pixel;

	int p = 0;

	if (mouse_x <= half_x_l && mouse_y <= half_y_t) { // Левый вверхний угол
		p = 1;
	}
	else if (mouse_x >= half_x_r && mouse_y <= half_y_t) { // Правый вверхний угол
		p = 2;
	}
	else if (mouse_x <= half_x_l && mouse_y >= half_y_b) { // Нижний левый угол
		p = 3;
	}
	else if (mouse_x >= half_x_r && mouse_y >= half_y_b) { // Нижний правый угол
		p = 4;
	}
	return p;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_PAINT: // main for drawing
	{
					   PAINTSTRUCT ps;
					   HDC hdc = ::BeginPaint(hWnd, &ps);
					   HPEN hPen = CreatePen(PS_SOLID, 2, RGB(193, 182, 182));
					   SelectObject(hdc, hPen);

					   RECT rcClient;
					   GetClientRect(hWnd, &rcClient);
					   int size_x = rcClient.right - rcClient.left;
					   int size_y = rcClient.bottom - rcClient.top;

					   drawLine(hdc, size_x / 2, 0, size_x / 2, size_y);
					   drawLine(hdc, 0, size_y / 2, size_x, size_y / 2);

					   int side = (int)GetWindowLong(hWnd, GWL_USERDATA);
					   if (GetWindowLong(hWnd, GWL_USERDATA) != 0){
						   drawRect(hdc, side, size_x, size_y);
					   }

					   DeleteObject(hPen);
					   ::EndPaint(hWnd, &ps);
	}
		break;
	case WM_MOUSEMOVE: {
						   TRACKMOUSEEVENT tme;
						   tme.cbSize = sizeof(tme);
						   tme.hwndTrack = hWnd;
						   tme.dwFlags = TME_LEAVE;
						   TrackMouseEvent(&tme);

						   POINT p;
						   GetCursorPos(&p);
						   if (ScreenToClient(hWnd, &p))
						   {
							   // trigger mouse move -> wm_paint
							   RECT rcClient;
							   GetClientRect(hWnd, &rcClient);
							   int size_x = rcClient.right - rcClient.left;
							   int size_y = rcClient.bottom - rcClient.top;

							   int side = getRECTSide(size_x, size_y, p);

							   if ((int)GetWindowLong(hWnd, GWL_USERDATA) != side){
								   SetWindowLong(hWnd, GWL_USERDATA, (LONG)side);
								   InvalidateRect(hWnd, NULL, true);
							   }
						   }
	}
		break;
	case WM_MOUSELEAVE:
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)0);
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
