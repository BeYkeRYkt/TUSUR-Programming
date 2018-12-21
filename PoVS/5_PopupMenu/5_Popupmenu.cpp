/**
* The MIT License (MIT)
*
* Copyright (c) 2018 Ruslan Nabeev
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
#include "5_Popupmenu.h"
#include "iostream"

// Names
#define ClazzName "5_Popupmenu"
#define MW "Main Window"
#define SIZE 256

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

	HWND  mainWindow = CreateWindow(wcex.lpszClassName, MW, WS_OVERLAPPEDWINDOW,
		X, Y, CX - X * 2, CY - 2 * Y, NULL, NULL, hInstance, NULL);

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
	switch (message) {
	case WM_RBUTTONDOWN: {
							 HMENU Hpop = CreatePopupMenu();
							 POINT p;
							 p.x = LOWORD(lParam);
							 p.y = HIWORD(lParam);
							 ClientToScreen(hWnd, &p);

							 //Strings
							 TCHAR sz[SIZE], str1[SIZE];
							 GetWindowText(hWnd, str1, SIZE);
							 for (int i = 100; i < 65536; i++) // зависит от ресурсов в StringTable
							 {
								 if (LoadString(GetModuleHandle(NULL), i, sz, sizeof(sz) / sizeof(TCHAR)) != 0)
								 {
									 if (strcmp(sz, str1) == 0)
									 {
										 AppendMenu(Hpop, MF_STRING, i, sz);
										 EnableMenuItem(Hpop, i, MF_GRAYED);
									 }
									 else
									 {
										 AppendMenu(Hpop, MF_STRING, i, sz);
										 EnableMenuItem(Hpop, i, MF_ENABLED);
									 }
								 }
							 }
							 // separator
							 AppendMenu(Hpop, MFT_SEPARATOR, NULL, NULL);

							 //bitmaps
							 AppendMenu(Hpop, MF_STRING | MF_POPUP, IDB_BITMAP1, "BITMAP 1");
							 AppendMenu(Hpop, MF_STRING | MF_POPUP, IDB_BITMAP2, "BITMAP 2");

							 if (GetWindowLong(hWnd, GWL_USERDATA) == 1)
							 {
								 EnableMenuItem(Hpop, IDB_BITMAP1, MF_DISABLED);
								 EnableMenuItem(Hpop, IDB_BITMAP2, MF_ENABLED);
							 }
							 else if (GetWindowLong(hWnd, GWL_USERDATA) == 2)
							 {
								 EnableMenuItem(Hpop, IDB_BITMAP2, MF_DISABLED);
								 EnableMenuItem(Hpop, IDB_BITMAP1, MF_ENABLED);
							 }
							 else {
								 EnableMenuItem(Hpop, IDB_BITMAP1, MF_ENABLED);
								 EnableMenuItem(Hpop, IDB_BITMAP2, MF_ENABLED);
							 }

							 TrackPopupMenu(Hpop,
								 TPM_CENTERALIGN | TPM_TOPALIGN | TPM_VERNEGANIMATION,
								 p.x, p.y, 0, hWnd, NULL);
							 DeleteObject(Hpop);
							 return 0;
	}
	case WM_COMMAND: {
						 switch (wParam) {
						 case IDB_BITMAP1: {
											   //load bitmap
											   HBRUSH hbr = CreatePatternBrush(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1)));

											   if (hbr != NULL){
												   //set place background
												   HBRUSH hOld = (HBRUSH)SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)hbr); // SetClassLong возвращает старое имаге
												   DeleteObject(hOld); // и удаляем его
												   InvalidateRect(hWnd, NULL, TRUE);
												   SetWindowLong(hWnd, GWL_USERDATA, 1);
											   }
											   return 0;
						 }

						 case IDB_BITMAP2: {
											   //load bitmap
											   HBRUSH hbr = CreatePatternBrush(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2)));

											   if (hbr != NULL){
												   //set place background
												   HBRUSH hOld = (HBRUSH)SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)hbr);
												   DeleteObject(hOld);
												   InvalidateRect(hWnd, NULL, TRUE);
												   SetWindowLong(hWnd, GWL_USERDATA, 2);
											   }
											   return 0;
						 }
						 case IDM_EXIT:
							 DestroyWindow(hWnd);
							 return 0;
						 default:
							 char buf[SIZE] = { 0 };
							 LoadString(GetModuleHandle(NULL), LOWORD(wParam), buf, SIZE);
							 SetWindowText(hWnd, buf);
							 return 0;
						 }
	}
	case WM_DESTROY: {
						 PostQuitMessage(0);
						 return 0;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}