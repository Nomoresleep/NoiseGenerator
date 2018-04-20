#include <windows.h>
#define ZLGL_IMPL
#include "glzl_core.hpp"

#pragma comment(lib, "opengl32.lib")

static void opengl_fatal_error(char *msg)
{
	MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
}

bool opengl_set_pixelformat(HDC hdc)
{
	int pixel_format_attribs[] = {
		WGL_DRAW_TO_WINDOW_ARB,     1,
		WGL_SUPPORT_OPENGL_ARB,     1,
		WGL_DOUBLE_BUFFER_ARB,      1,
		WGL_ACCELERATION_ARB,       WGL_FULL_ACCELERATION_ARB,
		WGL_PIXEL_TYPE_ARB,         WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB,         24,
		WGL_ALPHA_BITS_ARB,         8,
		WGL_DEPTH_BITS_ARB,         24,
		WGL_STENCIL_BITS_ARB,       8,
		0
	};

	int pixel_format;
	UINT num_formats;
	wglChoosePixelFormatARB(hdc, pixel_format_attribs, 0, 1, &pixel_format, &num_formats);
	if (!num_formats)
		return opengl_fatal_error("Failed to choose a modern OpenGL pixel format."), false;

	PIXELFORMATDESCRIPTOR pfd = {0};
	DescribePixelFormat(hdc, pixel_format, sizeof(pfd), &pfd);
	if (!SetPixelFormat(hdc, pixel_format, &pfd))
		return opengl_fatal_error("Failed to set the modern OpenGL pixel format."), false;

	return true;
}

HGLRC opengl_create_context(HDC hdc, int version_major, int version_minor)
{
    //Create OpenGL Context
    ZLGL_opengl_version glVersion;
    zlgl_OpenGLContextDescriptor ocd;
    ocd.DefFramebufferColorBits = 24;
    ocd.DefFramebufferDepthBits = 24;
    ocd.DefFramebufferAlphaBits = 8;
    ocd.DefFramebufferMultiSamples = 0;
    ocd.DefFramebufferStencilBits = 8;
    ocd.DebugContext = 0;
    ocd.EnableDoubleBuffering = 1;
    ocd.EnforceRequestedVersion = 1;
    ocd.EnableVSync = false;

    return zlgl_create_context(ZLGL_MAKE_VERSION(version_major, version_minor), hdc, &glVersion, &ocd);
}

void opengl_destroy_context(HGLRC hglrc)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hglrc);
}
