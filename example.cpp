#include <windows.h>
#include "borderless-window.h"
#include "opengl_context.h"

#include "glzl_core.hpp"
#include "imgui.h"
#include "imgui_impl_gl3.h"
#include "imgui_window.cpp"


static void imgui_window0(borderless_window_t *window, void * /*userdata*/)
{
	if (!imgui_window_begin(window, "Borderless OpenGL Window Example"))
	{
		borderless_window_close_all(window);
		PostQuitMessage(0);
	}

	ImGui::ShowStyleEditor(); // TODO: Replace this with your UI

	imgui_window_end();
}

static void imgui_window1(borderless_window_t * window, void * /*userdata*/)
{
	if (!imgui_window_begin(window, "Imgui!"))
		borderless_window_close(window);

	if (ImGui::Button("Create Window"))
		imgui_window_create(L"Foobar", 256, 256, imgui_window1, NULL);

	if (ImGui::Button("Destroy Window"))
		borderless_window_close(window);
	
	ImGui::Text(window->maximized ? "Maximized" : "Regular");

	imgui_window_end();
}

int CALLBACK wWinMain(HINSTANCE /*inst*/, HINSTANCE /*prev*/, LPWSTR /*cmd*/, int /*show*/)
{
	imgui_window_init(4, 3);
	imgui_window_create(L"Hello", 1280, 800, imgui_window0, NULL);
	imgui_window_create(L"World",  640, 480, imgui_window1, NULL);
	int result = imgui_window_message_loop();
	imgui_window_shutdown();
	return result;
}