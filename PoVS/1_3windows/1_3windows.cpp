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
#include "1_3windows.h"
#include "iostream"

// Names
#define ClazzName "1_3windows"
#define MW "Main Window (WS_OVERLAPPEDWINDOW)"
#define CW "Child Window (WS_CHILDWINDOW)"
#define PW "Popup Window (WS_POPUPWINDOW)"

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
	wcex.style =  CS_DBLCLKS;

	if (!RegisterClass(&wcex))
		return 0;

	HWND  mainWindow = CreateWindow(wcex.lpszClassName, MW, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (mainWindow == NULL)
		return 0;

	HWND  childWindow = CreateWindow(wcex.lpszClassName, CW, WS_CHILDWINDOW | WS_VISIBLE | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		CW_USEDEFAULT, 0, 500, 250, mainWindow, NULL, hInstance, NULL);

	if (childWindow == NULL)
		return 0;

	HWND  popupWindow = CreateWindow(wcex.lpszClassName, PW, WS_POPUPWINDOW | WS_VISIBLE | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		CW_USEDEFAULT, 0, 500, 550, 0, NULL, hInstance, NULL);

	if (popupWindow == NULL)
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
	switch (message)
	{
	case WM_LBUTTONDOWN:
		if (hWnd == FindWindow(ClazzName, MW)){
			HWND childHWnd = FindWindowEx(FindWindow(ClazzName, PW), NULL, ClazzName, CW);
			if (childHWnd != NULL){
				SetParent(childHWnd, hWnd);
				break;
			}
		}
		else if (hWnd == FindWindow(ClazzName, PW)){
			HWND childHWnd = FindWindowEx(FindWindow(ClazzName, MW), NULL, ClazzName, CW);
			if (childHWnd != NULL){
				SetParent(childHWnd, hWnd);
				break;
			}
		}
		break;
	case WM_RBUTTONDBLCLK:
		if (hWnd == FindWindow(ClazzName, PW)) {
			DWORD exWinStyle = GetWindowLong(hWnd, GWL_EXSTYLE);
			if ((exWinStyle & WS_EX_TOPMOST) == 0) {
				SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			} else {
				SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			}
			break;
		}
		break;
	case WM_DESTROY:
		if (hWnd == FindWindow(ClazzName, MW)){
			PostQuitMessage(0);
		}
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
