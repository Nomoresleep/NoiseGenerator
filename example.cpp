#include <windows.h>
#include <random>
#include "MCommon/mf_file.h"
#include "borderless-window.h"
#include "opengl_context.h"

#include "glzl_core.hpp"
#include "imgui.h"
#include "imgui_impl_gl3.h"
#include "imgui_window.cpp"
#include "workspace.h"
#include "dialogs.h"

#include "nodegraph.h"

#pragma comment(lib, "MCommon.lib")
#pragma comment(lib, "Dbghelp.lib")

static f32 zoom = 1.0f;
static const f32 zoom_min = 0.2f;
static const f32 zoom_max = 20.0f;

static f32 frequency = 1.0f;
static const f32 frequency_min = 0.01f;
static const f32 frequency_max = 20.0f;

static void locShowTexturePreview()
{
	if (ImGui::Button("-", ImVec2(ImGui::GetTextLineHeightWithSpacing(), ImGui::GetTextLineHeightWithSpacing()))) zoom = min(zoom_max, max(zoom_min, zoom - 0.1f));
	ImGui::SameLine();
	ImGui::SliderFloat("zoom_slider", &zoom, zoom_min, zoom_max);
	ImGui::SameLine();
	if (ImGui::Button("+")) zoom = min(zoom_max, max(zoom_min, zoom + 0.1f));
	ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0, 0, 0, 1));
	ImGui::BeginChild("2", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	if (ImGui::IsWindowHovered())
	{
		zoom = min(zoom_max, max(zoom_min, zoom + ImGui::GetIO().MouseWheel * 0.1f));
	}
	ImVec2 imageSize = { zoom * (f32)theWorkspace->myImageSize.x, zoom * (f32)theWorkspace->myImageSize.y };

	//NOTE:[NoMoreSleep] Button necessary for Item activiation query
	ImGui::ImageButton((void*)theWorkspace->myImageTextureID, imageSize, ImVec2(0, 0), ImVec2(1, 1), 0);

	if (ImGui::IsItemActive())
	{
		ImGuiIO& io = ImGui::GetIO();
		ImVec2 mouseDelta = ImVec2(io.MousePos.x - io.MouseClickedPos[0].x, io.MousePos.y - io.MouseClickedPos[0].y);
		if (mouseDelta.x != 0)
		{
			ImGui::SetScrollX(ImGui::GetScrollX() - mouseDelta.x);
			ImGui::SetScrollY(ImGui::GetScrollY() - mouseDelta.y);
			ImGui::ResetMouseDragDelta();
		}
	}
	ImGui::EndChild();
	ImGui::PopStyleColor();
}

static void HandleDialogs()
{
	static const ImGuiWindowFlags modalFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;

	bool newFileOpen = true;
	if (ImGui::BeginPopupModal(theNewFileDialogID, &newFileOpen, modalFlags))
	{
		ShowNewFileDialog();
		ImGui::EndPopup();
	}

	bool exportOpen = true;
	if (ImGui::BeginPopupModal(theExportDialogID, &exportOpen, modalFlags))
	{
		if (theWorkspace)
		{
			ShowExportDialog();
			ImGui::EndPopup();
		}
		else
		{
			ImGui::CloseCurrentPopup();
			ImGui::EndPopup();
		}
	}

	bool gpuCapsOpen = true;
	if (ImGui::BeginPopupModal(theGPUCapabilitiesDialogID, &gpuCapsOpen, modalFlags))
	{
		ShowGPUCapabilitiesDialog();
		ImGui::EndPopup();
	}

	bool aboutOpen = true;
	if (ImGui::BeginPopupModal(theAboutDialogID, &aboutOpen, modalFlags))
	{
		ShowAboutDialog();
		ImGui::EndPopup();
	}
}

static void app_main_loop(borderless_window_t *window, void * /*userdata*/)
{
    if (!window->initialized)
        return;

	static bool openContextMenu = false;
	if (!imgui_window_begin(window, "NoiseGenerator", &openContextMenu))
	{
		borderless_window_close_all(window);
		PostQuitMessage(0);
	}
	imgui_window_menu_bar(window);

	HandleDialogs();

	imgui_window_context_menu(window, openContextMenu);

    if (theWorkspace)
    {
        ImGui::Columns(2);
        locShowTexturePreview();
        ImGui::NextColumn();
        ShowNodeGraph(theWorkspace->myNodegraph);
    }
	imgui_window_end();
}

static void app_init_resources()
{
	i32 permutationBuffer12[512];
	i32 permutationBuffer[512];

	std::mt19937_64 gen(1337);

	for (i32 i = 0; i < 256; i++)
		permutationBuffer[i] = i;

	for (i32 j = 0; j < 256; j++)
	{
		i32 rng = (i32)(gen() % (256 - j));
		i32 k = rng + j;
		i32 l = permutationBuffer[j];
		permutationBuffer[j] = permutationBuffer[j + 256] = permutationBuffer[k];
		permutationBuffer[k] = l;
		permutationBuffer12[j] = permutationBuffer12[j + 256] = permutationBuffer[j] % 12;
	}

	GLuint permBufferID;
	glGenBuffers(1, &permBufferID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, permBufferID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(permutationBuffer), permutationBuffer, GL_STATIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, permBufferID);

	GLuint permBuffer12ID;
	glGenBuffers(1, &permBuffer12ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, permBuffer12ID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(permutationBuffer12), permutationBuffer12, GL_STATIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, permBuffer12ID);
}

i32 CALLBACK wWinMain(HINSTANCE /*inst*/, HINSTANCE /*prev*/, LPWSTR /*cmd*/, int /*show*/)
{
	imgui_window_init(4, 3);
	imgui_window_create(L"NoiseGenerator", 1920, 1000, app_main_loop, NULL);

	app_init_resources();

	i32 result = imgui_window_message_loop();
	imgui_window_shutdown();
	return result;
}