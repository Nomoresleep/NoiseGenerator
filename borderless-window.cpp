/* borderless-window - a minimal borderless window with the Windows API
 *
 * Written in 2016 by James Ross-Gowan, modified in 2018 by Andreas Mantler
 *
 * To the extent possible under law, the author(s) have dedicated all copyright
 * and related and neighboring rights to this software to the public domain
 * worldwide. This software is distributed without any warranty.
 *
 * See <https://creativecommons.org/publicdomain/zero/1.0/> for a copy of the
 * CC0 Public Domain Dedication, which applies to this software.
 */

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>
#include <malloc.h>
#include "borderless-window.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "dwmapi.lib")

static BOOL GetClientRectInScreenSpace(borderless_window_t *window, LPRECT rect)
{
	RECT clientArea;
	if (!GetClientRect(window->hwnd, &clientArea))
		return FALSE;
	POINT tlClientArea = { clientArea.left, clientArea.top };
	if (!ClientToScreen(window->hwnd, &tlClientArea))
		return FALSE;

	rect->left = tlClientArea.x;
	rect->top = tlClientArea.y;
	rect->right = tlClientArea.x + clientArea.right;
	rect->bottom = tlClientArea.y + clientArea.bottom;

	return TRUE;
}

static BOOL IsLeftSnapped(LPRECT clientRect, LPRECT monitorRect)
{
	s32 monitorWHalf = (monitorRect->right - monitorRect->left) >> 1;
	s32 clientW = clientRect->right - clientRect->left;
	if (clientRect->top == monitorRect->top && clientRect->left == monitorRect->left && clientRect->bottom == monitorRect->bottom && monitorWHalf == clientW)
		return TRUE;
	else
		return FALSE;
}

static BOOL IsRightSnapped(LPRECT clientRect, LPRECT monitorRect)
{
	s32 monitorWHalf = (monitorRect->right - monitorRect->left) >> 1;
	s32 clientW = clientRect->right - clientRect->left;
	if (clientRect->top == monitorRect->top && clientRect->left == (monitorRect->left + monitorWHalf) && clientRect->bottom == monitorRect->bottom && monitorWHalf == clientW)
		return TRUE;
	else
		return FALSE;
}

static HMONITOR GetNextMonitorRight(LPRECT monitorRect)
{
	POINT pt = { monitorRect->right + 1, (monitorRect->bottom - monitorRect->top) >> 1 };
	HMONITOR nextMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONULL);
	if (nextMonitor)
		return nextMonitor;
	pt.x = -MAXLONG;
	nextMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
	return nextMonitor;
}

static HMONITOR GetNextMonitorLeft(LPRECT monitorRect)
{
	POINT pt = { monitorRect->left - 1, (monitorRect->bottom - monitorRect->top) >> 1 };
	HMONITOR nextMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONULL);
	if (nextMonitor)
		return nextMonitor;
	pt.x = MAXLONG;
	nextMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
	return nextMonitor;
}

static void handle_snap_left(borderless_window_t *window, LPRECT clientRect, LPRECT monitorWork, LPRECT monitor)
{
    if (window->maximized)
        ShowWindow(window->hwnd, SW_RESTORE);

    s32 w = monitorWork->right - monitorWork->left;
    s32 h = monitorWork->bottom - monitorWork->top;
    if (IsLeftSnapped(clientRect, monitorWork))
    {
        //Note:[NoMoreSleep] Already snapped, select next monitor to snap to
        HMONITOR nextMonitor = GetNextMonitorLeft(monitor);
        MONITORINFO monitorInfo = {};
        monitorInfo.cbSize = sizeof(monitorInfo);
        GetMonitorInfoW(nextMonitor, &monitorInfo);
        RECT &r = monitorInfo.rcWork;
        w = r.right - r.left;
        h = r.bottom - r.top;
        SetWindowPos(window->hwnd, HWND_TOP, r.left + w / 2, r.top, w / 2, h, NULL);
    }
    else if (IsRightSnapped(clientRect, monitorWork))
    {
        RECT &r = window->tile_restore_rect;
        SetWindowPos(window->hwnd, HWND_TOP, r.left, r.top, r.right - r.left, r.bottom - r.top, NULL);
    }
    else
    {
        SetWindowPos(window->hwnd, HWND_TOP, monitorWork->left, monitorWork->top, w / 2, h, NULL);
        window->tile_restore_rect = *clientRect;
    }
}

static void handle_snap_right(borderless_window_t *window, LPRECT clientRect, LPRECT monitorWork, LPRECT monitor)
{
    if(window->maximized)
        ShowWindow(window->hwnd, SW_RESTORE);

    s32 w = monitorWork->right - monitorWork->left;
    s32 h = monitorWork->bottom - monitorWork->top;
    if (IsRightSnapped(clientRect, monitorWork))
    {
        //Note:[NoMoreSleep] Already snapped, select next monitor to snap to
        HMONITOR nextMonitor = GetNextMonitorRight(monitor);
        MONITORINFO monitorInfo = {};
        monitorInfo.cbSize = sizeof(monitorInfo);
        GetMonitorInfoW(nextMonitor, &monitorInfo);
        RECT &r = monitorInfo.rcWork;
        w = r.right - r.left;
        h = r.bottom - r.top;
        SetWindowPos(window->hwnd, HWND_TOP, r.left, r.top, w / 2, h, NULL);
    }
    else if (IsLeftSnapped(clientRect, monitorWork))
    {
        RECT &r = window->tile_restore_rect;
        SetWindowPos(window->hwnd, HWND_TOP, r.left, r.top, r.right - r.left, r.bottom - r.top, NULL);
    }
    else
    {
        SetWindowPos(window->hwnd, HWND_TOP, monitorWork->left + w / 2, monitorWork->top, w / 2, h, NULL);
        window->tile_restore_rect = *clientRect;
    }
}

static void handle_compositionchanged(borderless_window_t *window)
{
	BOOL enabled = FALSE;
#if 0
	DwmIsCompositionEnabled(&enabled);
	window->composition_enabled = enabled == TRUE;

	if (enabled) 
	{
		MARGINS m = {0};
		m.cyTopHeight = 1;
		DwmExtendFrameIntoClientArea(window->hwnd, &m);
		DWORD state = DWMNCRP_ENABLED;
		DwmSetWindowAttribute(window->hwnd, DWMWA_NCRENDERING_POLICY, &state, sizeof(DWORD));
	}
#endif
}

static LRESULT handle_nchittest(borderless_window_t *window, s32 x, s32 y)
{
	if (IsMaximized(window->hwnd))
		return HTCLIENT;

	POINT mouse = { x, y };
	ScreenToClient(window->hwnd, &mouse);

	/* The horizontal frame should be the same size as the vertical frame,
	   since the NONCLIENTMETRICS structure does not distinguish between them */
	s32 frame_size = GetSystemMetrics(SM_CXFRAME); // + GetSystemMetrics(SM_CXPADDEDBORDER);
	/* The diagonal size handles are wider than the frame */
	s32 diagonal_width = frame_size * 2 + GetSystemMetrics(SM_CXBORDER);

	if (mouse.y < frame_size) 
	{
		if (mouse.x < diagonal_width)
			return HTTOPLEFT;
		if (mouse.x >= (s32)window->width - diagonal_width)
			return HTTOPRIGHT;
		return HTTOP;
	}

	if (mouse.y >= (s32)window->height - frame_size) 
	{
		if (mouse.x < diagonal_width)
			return HTBOTTOMLEFT;
		if (mouse.x >= (s32)window->width - (s32)diagonal_width)
			return HTBOTTOMRIGHT;
		return HTBOTTOM;
	}

	if (mouse.x < frame_size)
		return HTLEFT;
	if (mouse.x >= (s32)window->width - frame_size)
		return HTRIGHT;
	return HTCLIENT;
}

static LRESULT CALLBACK borderless_window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	borderless_window_t *window = (borderless_window_t*)GetWindowLongPtrW(hwnd, GWLP_USERDATA);
	if (!window)
	{
		if (msg == WM_NCCREATE)
		{
			CREATESTRUCTW *createStruct = (CREATESTRUCTW*)lparam;
			window = (borderless_window_t*)createStruct->lpCreateParams;
			window->hwnd = hwnd;
			window->hdc = GetDC(hwnd);
			window->width = createStruct->cx;
			window->height = createStruct->cy;
			SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)window);
		}
		return DefWindowProcW(hwnd, msg, wparam, lparam);
	}

	switch (msg) 
	{
	case WM_DWMCOMPOSITIONCHANGED:
		handle_compositionchanged(window);
		return 0;
	case WM_NCHITTEST:
		return handle_nchittest(window, GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
	case WM_PAINT:
		if (window->painting) // Prevent recursive pai32ing
			return DefWindowProcW(hwnd, msg, wparam, lparam);
		window->painting = true;
		break;
	case WM_SIZE:
		window->minimized = wparam == SIZE_MINIMIZED;
		window->maximized = wparam == SIZE_MAXIMIZED;

		if (window->maximized && (window->width != LOWORD(lparam) || window->height != HIWORD(lparam)))
		{
			const POINT zero = { 0, 0 };
			HMONITOR monitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);

			MONITORINFO monitorInfo = {};
			monitorInfo.cbSize = sizeof(monitorInfo);
			if (GetMonitorInfoW(monitor, &monitorInfo))
			{
				RECT &r = monitorInfo.rcWork;
				window->width = r.right - r.left;
				window->height = r.bottom - r.top;
				SetWindowPos(hwnd, HWND_TOP, r.left, r.top, window->width, window->height, NULL);
				return 0;
			}
		}

		window->width = LOWORD(lparam);
		window->height = HIWORD(lparam);
		return 0;
    case WM_KEYUP:
        if (((GetKeyState(VK_LWIN) & 0x8000) != 0 ||
            (GetKeyState(VK_RWIN) & 0x8000) != 0) &&
            (wparam == VK_LEFT ||
                wparam == VK_RIGHT ||
                wparam == VK_DOWN ||
                wparam == VK_UP))
        {
            HMONITOR windowMonitor = MonitorFromWindow(window->hwnd, MONITOR_DEFAULTTONEAREST);
            MONITORINFO monitorInfo = {};
            monitorInfo.cbSize = sizeof(monitorInfo);

            if (!GetMonitorInfoW(windowMonitor, &monitorInfo))
                break;

            RECT clientRect;
            if (!GetClientRectInScreenSpace(window, &clientRect))
                break;

            if (wparam == VK_LEFT)
            {
                handle_snap_left(window, &clientRect, &monitorInfo.rcWork, &monitorInfo.rcMonitor);
            }
            else if (wparam == VK_RIGHT)
            {
                handle_snap_right(window, &clientRect, &monitorInfo.rcWork, &monitorInfo.rcMonitor);
            }
            else if (wparam == VK_DOWN)
            {
                if (IsLeftSnapped(&clientRect, &monitorInfo.rcWork) || IsRightSnapped(&clientRect, &monitorInfo.rcWork))
                {
                    RECT &r = window->tile_restore_rect;
                    SetWindowPos(window->hwnd, HWND_TOP, r.left, r.top, r.right - r.left, r.bottom - r.top, NULL);
                }
                else
                    ShowWindow(hwnd, SW_RESTORE);
            }
            else if (wparam == VK_UP)
            {
                ShowWindow(hwnd, SW_MAXIMIZE);
            }
        }
        break;
	}

	LRESULT result = window->handler(window, msg, wparam, lparam) ? 0 : DefWindowProcW(hwnd, msg, wparam, lparam);

	if (msg == WM_PAINT)
		window->painting = false;
	else if (msg == WM_CLOSE || msg == WM_QUIT)
	{
		DestroyWindow(hwnd);
		free(window);
		return 0;
	}

	return result;
}

void borderless_window_register()
{
	WNDCLASSEXW wc = {0};
	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;
	wc.lpfnWndProc = borderless_window_proc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszClassName = L"borderless-window";
	RegisterClassExW(&wc);
}

void borderless_window_unregister()
{
	UnregisterClassW(L"borderless-window", GetModuleHandle(NULL));
}

borderless_window_t* borderless_window_create(LPCWSTR title, s32 width, s32 height, message_handler handler, void* userdata)
{
	borderless_window_t *window = (borderless_window_t*)calloc(1, sizeof(borderless_window_t));

	window->handler = handler;
	window->userdata = userdata;

	CreateWindowExW(
		WS_EX_APPWINDOW | WS_EX_LAYERED,
		L"borderless-window",
		title,
		//NOTE:[NoMoreSleep] WS_THICKFRAME is required for "native" aero snap feature
		WS_POPUP | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL, NULL, GetModuleHandle(NULL), window);

	// Necessary if you want compositing to work properly with alpha blending:
	SetLayeredWindowAttributes(window->hwnd, RGB(255, 0, 255), 255, LWA_COLORKEY);

	handle_compositionchanged(window);

	return window;
}

static BOOL CALLBACK enum_thread_window(HWND hwnd, LPARAM /*lParam*/)
{
	PostMessageW(hwnd, WM_CLOSE, 0, 0);
	return TRUE;
}

void borderless_window_close_all(borderless_window_t *root)
{
	EnumThreadWindows(GetWindowThreadProcessId(root->hwnd, 0), enum_thread_window, NULL);
}

void borderless_window_close(borderless_window_t *window)
{
	PostMessageW(window->hwnd, WM_CLOSE, 0, 0);
}
