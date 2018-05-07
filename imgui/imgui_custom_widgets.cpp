#include "imgui_custom_widgets.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"

//TODO:[Nomoresleep]
//- make Number text clip label text
//- hide label on text input
//- color consistency
IMGUI_API bool ImGui::DragFloatProgress(const char* label, float* v, float v_speed, float v_min, float v_max, const char* display_format, float power)
{
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const float w = CalcItemWidth();

	const ImVec2 label_size = CalcTextSize(label, NULL, true);
	const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(w, label_size.y + style.FramePadding.y*2.0f));
	const ImRect inner_bb(frame_bb.Min + style.FramePadding, frame_bb.Max - style.FramePadding);
	const ImRect total_bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0.0f));

	// NB- we don't call ItemSize() yet because we may turn into a text edit box below
	if (!ItemAdd(total_bb, id, &frame_bb))
	{
		ItemSize(total_bb, style.FramePadding.y);
		return false;
	}
	const bool hovered = ItemHoverable(frame_bb, id);
	
	if (!display_format)
		display_format = "%.3f";
	int decimal_precision = ParseFormatPrecision(display_format, 3);
	
	// Tabbing or CTRL-clicking on Drag turns it into an input box
	bool start_text_input = false;
	const bool tab_focus_requested = FocusableItemRegister(window, id);
	if (tab_focus_requested || (hovered && (g.IO.MouseClicked[0] || g.IO.MouseDoubleClicked[0])) || g.NavActivateId == id || (g.NavInputId == id && g.ScalarAsInputTextId != id))
	{
		SetActiveID(id, window);
		SetFocusID(id, window);
		FocusWindow(window);
		g.ActiveIdAllowNavDirFlags = (1 << ImGuiDir_Up) | (1 << ImGuiDir_Down);
		if (tab_focus_requested || g.IO.KeyCtrl || g.IO.MouseDoubleClicked[0] || g.NavInputId == id)
		{
			start_text_input = true;
			g.ScalarAsInputTextId = 0;
		}
	}
	if (start_text_input || (g.ActiveId == id && g.ScalarAsInputTextId == id))
		return InputScalarAsWidgetReplacement(frame_bb, label, ImGuiDataType_Float, v, id, decimal_precision);

	// Actual drag behavior
	ItemSize(total_bb, style.FramePadding.y);
	ImGui::PushStyleColor(ImGuiCol_FrameBgActive, style.Colors[ImGuiCol_FrameBg]);
	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, style.Colors[ImGuiCol_FrameBg]);
	const bool value_changed = DragBehavior(frame_bb, id, v, v_speed, v_min, v_max, decimal_precision, power);
	ImGui::PopStyleColor(2);
	ImVec2 max = ImVec2(frame_bb.Min.x + (frame_bb.Max.x - frame_bb.Min.x) * MC_Clamp((*v - v_min)/(v_max - v_min), 0.0f, 1.0f), frame_bb.Max.y);
	RenderFrame(frame_bb.Min, max, GetColorU32(hovered ? style.Colors[ImGuiCol_FrameBgActive] : style.Colors[ImGuiCol_FrameBgHovered]), true, style.FrameRounding);
	// Display value using user-provided display format so user can add prefix/suffix/decorations to the value.
	char value_buf[64];
	const char* value_buf_end = value_buf + ImFormatString(value_buf, IM_ARRAYSIZE(value_buf), display_format, *v);
	RenderTextClipped(frame_bb.Min, frame_bb.Max - ImVec2(style.ItemInnerSpacing.x, 0), value_buf, value_buf_end, NULL, ImVec2(1.0f, 0.5f));

	RenderText(ImVec2(frame_bb.Min.x + style.ItemInnerSpacing.x, inner_bb.Min.y), label);

	return value_changed;
}