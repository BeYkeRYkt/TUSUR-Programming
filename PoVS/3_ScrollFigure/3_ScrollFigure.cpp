/**
* The MIT License (MIT)
*
* Copyright (c) 2018 Vasily Maximov
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
#include "3_ScrollFigure.h"
#include "time.h"

// Names
#define ClazzName "3_ScrollFigure"
#define MW "Main Window"

// Global params
HINSTANCE hInst;
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

#define PAGE 200
#define LINE 24

#define M 3000
#define R 50

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

	int cX = (GetSystemMetrics(SM_CXSCREEN));
	int cY = (GetSystemMetrics(SM_CYSCREEN));
	int X = cX / 10;
	int Y = cY / 10;

	HMENU hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDC_MY3_SCROLLFIGURE));
	HWND mainWindow = CreateWindow(wcex.lpszClassName, MW, WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
		X, Y, cX - 2 * X, cY - 2 * Y, NULL, hMenu, hInstance, NULL);

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

// field
const int N = 500;
int X[N];
int Y[N];

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
					  srand(unsigned(time(NULL))); // set random

					  for (int i = 0; i < N; i++) {
						  X[i] = rand() % M;
						  Y[i] = rand() % M;
					  }
					  EnableMenuItem(GetMenu(hwnd), IDM_FIGURE_SQUARE, MF_ENABLED);
					  EnableMenuItem(GetMenu(hwnd), IDM_FIGURE_CIRCLE, MF_DISABLED);
					  break;
	}
	case WM_COMMAND:
	{
					   switch (wParam)
					   {
					   case IDM_EXIT: //Выход
					   {
										  DestroyWindow(hwnd);
										  return 0;
					   }
					   case IDM_FIGURE_CIRCLE:
					   {
												 SetWindowLong(hwnd, GWL_USERDATA, 0);
												 InvalidateRect(hwnd, NULL, true);
												 EnableMenuItem(GetMenu(hwnd), IDM_FIGURE_SQUARE, MF_ENABLED);
												 EnableMenuItem(GetMenu(hwnd), IDM_FIGURE_CIRCLE, MF_DISABLED);
												 break;
					   }
					   case IDM_FIGURE_SQUARE:
					   {
												 SetWindowLong(hwnd, GWL_USERDATA, 1);
												 InvalidateRect(hwnd, NULL, true);
												 EnableMenuItem(GetMenu(hwnd), IDM_FIGURE_CIRCLE, MF_ENABLED);
												 EnableMenuItem(GetMenu(hwnd), IDM_FIGURE_SQUARE, MF_DISABLED);
												 break;
					   }
					   }
					   break;
	}
	case WM_SIZE:
	{
					RECT Rect;
					GetClientRect(hwnd, &Rect);

					// horizontal
					SCROLLINFO hscroll = { 0 };
					hscroll.cbSize = sizeof(SCROLLINFO);
					hscroll.fMask = SIF_RANGE;
					hscroll.nMax = M - Rect.right;
					hscroll.nMin = 0;

					SetScrollInfo(hwnd, SB_HORZ, &hscroll, true);

					// vertical
					SCROLLINFO vscroll = { 0 };
					vscroll.cbSize = sizeof(SCROLLINFO);
					vscroll.fMask = SIF_RANGE;
					vscroll.nMax = M - Rect.bottom;
					vscroll.nMin = 0;

					SetScrollInfo(hwnd, SB_VERT, &vscroll, true);

					InvalidateRect(hwnd, NULL, true);
					return 0;
	}

	case WM_PAINT:
	{
					 SCROLLINFO hscroll = { 0 };
					 hscroll.cbSize = sizeof(SCROLLINFO);
					 hscroll.fMask = SIF_POS;
					 GetScrollInfo(hwnd, SB_HORZ, &hscroll);

					 SCROLLINFO vscroll = { 0 };
					 vscroll.cbSize = sizeof(SCROLLINFO);
					 vscroll.fMask = SIF_POS;
					 GetScrollInfo(hwnd, SB_VERT, &vscroll);

					 RECT scRect, Rect, Buff;
					 PAINTSTRUCT Paint;

					 GetClientRect(hwnd, &Rect);

					 HDC hdc = ::BeginPaint(hwnd, &Paint);

					 // brushes
					 HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0)); //красный
					 HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255)); //синий

					 for (int i = 0; i < N; i++)
					 {
						 scRect.right = X[i] + R - hscroll.nPos;
						 scRect.left = X[i] - R - hscroll.nPos;
						 scRect.top = Y[i] - R - vscroll.nPos;
						 scRect.bottom = Y[i] + R - vscroll.nPos;

						 if (IntersectRect(&Buff, &Paint.rcPaint, &scRect))
						 {
							 if (i % 2 == 0) {
								 SelectObject(hdc, redBrush);
							 }
							 else {
								 SelectObject(hdc, blueBrush);
							 }

							 switch (GetWindowLong(hwnd, GWL_USERDATA))
							 {
							 case 0: {
										 Ellipse(hdc, scRect.left, scRect.top, scRect.right, scRect.bottom);
										 break;
							 }
							 case 1: {
										 Rectangle(hdc, scRect.left, scRect.top, scRect.right, scRect.bottom);
										 break;
							 }
								 break;
							 }

						 }
					 }

					 // delete objects
					 DeleteObject(redBrush);
					 DeleteObject(blueBrush);

					 ::EndPaint(hwnd, &Paint);
					 return 0;
	}

	case WM_HSCROLL:
	{
					   SCROLLINFO hscroll = { 0 };
					   hscroll.cbSize = sizeof(SCROLLINFO);
					   hscroll.fMask = SIF_RANGE | SIF_POS | SIF_TRACKPOS;
					   GetScrollInfo(hwnd, SB_HORZ, &hscroll);

					   RECT rc;
					   GetClientRect(hwnd, &rc);

					   int xPos = hscroll.nPos;

					   switch (LOWORD(wParam))
					   {
					   case SB_LINERIGHT:
					   {
											hscroll.nPos += LINE;
											if (hscroll.nPos > hscroll.nMax) {
												hscroll.nPos = hscroll.nMax;
											}
											break;

					   }
					   case SB_PAGERIGHT:
					   {
											hscroll.nPos += PAGE;
											if (hscroll.nPos > hscroll.nMax) {
												hscroll.nPos = hscroll.nMax;
											}
											break;
					   }
					   case SB_LINELEFT:
					   {
										   hscroll.nPos -= LINE;
										   if (hscroll.nPos < hscroll.nMin) {
											   hscroll.nPos = hscroll.nMin;
										   }
										   break;
					   }
					   case SB_PAGELEFT:
					   {
										   hscroll.nPos -= PAGE;
										   if (hscroll.nPos < hscroll.nMin) {
											   hscroll.nPos = hscroll.nMin;
										   }
										   break;
					   }

					   case SB_THUMBTRACK:
					   {
											 hscroll.nPos = hscroll.nTrackPos;
											 break;
					   }
					   }

					   if (hscroll.nPos != xPos)
					   {
						   SetScrollInfo(hwnd, SB_HORZ, &hscroll, true);
						   ScrollWindow(hwnd, xPos - hscroll.nPos, 0, NULL, NULL);

						   if (xPos - hscroll.nPos > 0)
						   {
							   rc.left = rc.right - (xPos - hscroll.nPos);
						   }
						   else
						   {
							   rc.right = rc.left + (xPos - hscroll.nPos);
						   }
						   InvalidateRect(hwnd, &rc, true);

					   }
					   return 0;
	}

	case WM_VSCROLL:
	{
					   SCROLLINFO vscroll = { 0 };
					   vscroll.cbSize = sizeof(SCROLLINFO);
					   vscroll.fMask = SIF_RANGE | SIF_POS | SIF_TRACKPOS;
					   GetScrollInfo(hwnd, SB_VERT, &vscroll);

					   RECT rc;
					   GetClientRect(hwnd, &rc);

					   int yPos = vscroll.nPos;
					   switch (LOWORD(wParam))
					   {
					   case SB_LINEDOWN:
					   {
										   vscroll.nPos += LINE;
										   if (vscroll.nPos > vscroll.nMax) {
											   vscroll.nPos = vscroll.nMax;
										   }
										   break;
					   }
					   case SB_PAGEDOWN:
					   {
										   vscroll.nPos += PAGE;
										   if (vscroll.nPos > vscroll.nMax) {
											   vscroll.nPos = vscroll.nMax;
										   }
										   break;
					   }

					   case SB_LINEUP:
					   {
										 vscroll.nPos -= LINE;
										 if (vscroll.nPos < vscroll.nMin) {
											 vscroll.nPos = vscroll.nMin;
										 }
										 break;
					   }
					   case SB_PAGEUP:
					   {
										 vscroll.nPos -= PAGE;
										 if (vscroll.nPos < vscroll.nMin) {
											 vscroll.nPos = vscroll.nMin;
										 }
										 break;
					   }
					   case SB_TOP:
					   {
									  vscroll.nPos = vscroll.nMax;
									  break;
					   }
					   case SB_BOTTOM:
					   {
										 vscroll.nPos = vscroll.nMin;
										 break;
					   }
					   case SB_THUMBTRACK:
					   {
											 vscroll.nPos = vscroll.nTrackPos;
											 break;
					   }
					   }

					   if (vscroll.nPos != yPos)
					   {
						   SetScrollInfo(hwnd, SB_VERT, &vscroll, true);
						   ScrollWindow(hwnd, 0, yPos - vscroll.nPos, NULL, NULL);
						   if (yPos - vscroll.nPos > 0)
						   {
							   rc.top = rc.bottom - (yPos - vscroll.nPos);
						   }
						   else
						   {
							   rc.bottom = rc.top + (yPos - vscroll.nPos);
						   }
						   InvalidateRect(hwnd, &rc, true);
					   }
					   return 0;
	}

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_UP:
		{
					  PostMessage(hwnd, WM_VSCROLL, SB_LINEUP, NULL);
					  return 0;
		}
		case VK_DOWN:
		{
						PostMessage(hwnd, WM_VSCROLL, SB_LINEDOWN, NULL);
						return 0;
		}
		case VK_RIGHT:
		{
						 PostMessage(hwnd, WM_HSCROLL, SB_LINERIGHT, NULL);
						 return 0;
		}
		case VK_LEFT:
		{
						PostMessage(hwnd, WM_HSCROLL, SB_LINELEFT, NULL);
						return 0;
		}

		case VK_PRIOR: //pg up
		{
						   PostMessage(hwnd, WM_VSCROLL, SB_PAGEUP, NULL);
						   return 0;
		}
		case VK_NEXT: // pg down
		{
						  PostMessage(hwnd, WM_VSCROLL, SB_PAGEDOWN, NULL);
						  return 0;
		}
		case VK_HOME:
		{
						PostMessage(hwnd, WM_VSCROLL, SB_TOP, NULL);
						return 0;
		}
		case VK_END:
		{
					   PostMessage(hwnd, WM_VSCROLL, SB_BOTTOM, NULL);
					   return 0;
		}
		case VK_ESCAPE:
			DestroyWindow(hwnd);
		default:
			return 0;
		}

	case WM_MOUSEWHEEL:
	{
						  if ((int) wParam > 0){
							  PostMessage(hwnd, WM_VSCROLL, SB_LINEUP, NULL);
						  }
						  else {
							  PostMessage(hwnd, WM_VSCROLL, SB_LINEDOWN, NULL);
						  }
						  break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
