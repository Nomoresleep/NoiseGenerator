#pragma once

#include <Windows.h>
#include "MC_Base.h"
#include "glzl_core.hpp"

HGLRC opengl_create_context(HDC hdc, s32 version_major, s32 version_minor);
bool opengl_set_pixelformat(HDC hdc); // Call this on other windows that you want to use the created context on
void opengl_destroy_context(HGLRC hglrc);
