#pragma once

#include "imgui.h"

namespace ImGui
{
	IMGUI_API bool DragFloatProgress(const char* label, float* v, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* display_format = "%.3f", float power = 1.0f);
}