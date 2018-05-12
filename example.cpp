#include <windows.h>
#include <random>
#include "MC_IniFile.h"
#include "borderless-window.h"

#include "opengl_context.h"
#include "imgui/imgui.h"
#include "imgui/imgui_window.h"

#include "opengl_context.h"
#include "workspace.h"
#include "dialogs.h"
#include "filedialog.h"
#include "NG_GraphRunner.h"
#include "NG_NodeGraph.h"
#include "Editor_NodeEditor.h"

#pragma comment(lib, "MCommon.lib")
#pragma comment(lib, "Editor.lib")
#pragma comment(lib, "Dbghelp.lib")

static f32 zoom = 1.0f;
static const f32 zoom_min = 0.2f;
static const f32 zoom_max = 20.0f;

static const char* thePathToIni = "NoiseGen.ini";
static FileDialog theFileDialog;

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
    theFileDialog.Show();
}

static void app_main_loop(borderless_window_t *window, void * /*userdata*/)
{
    if (!window->initialized)
        return;

    MC_IniFile iniFile(thePathToIni);
    iniFile.SetUInt("WindowWidth", window->width);
    iniFile.SetUInt("WindowHeight", window->height);
    iniFile.WriteToFile();

    if (theWorkspace)
    {
        NG_GraphRunner runner(theWorkspace->myNodeGraph);
        runner.Run();
		theWorkspace->SetProgramSource(runner.mySource);
    }

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
		theWorkspace->myNodeEditor->Display();
    }
	imgui_window_end();
}

static void app_init_resources()
{
	s32 permutationBuffer12[512];
	s32 permutationBuffer[512];

	std::mt19937_64 gen(1337);

	for (s32 i = 0; i < 256; i++)
		permutationBuffer[i] = i;

	for (s32 j = 0; j < 256; j++)
	{
		s32 rng = (s32)(gen() % (256 - j));
		s32 k = rng + j;
		s32 l = permutationBuffer[j];
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

s32 CALLBACK wWinMain(HINSTANCE /*inst*/, HINSTANCE /*prev*/, LPWSTR /*cmd*/, int /*show*/)
{
    MC_IniFile iniFile(thePathToIni);
    iniFile.Process();
    u32 width = iniFile.GetUInt("WindowWidth", 1920);
    u32 height = iniFile.GetUInt("WindowHeight", 1000);

	imgui_window_init(4, 3);
	imgui_window_create(L"NoiseGenerator", width, height, app_main_loop, NULL);

	app_init_resources();

	s32 result = imgui_window_message_loop();
	imgui_window_shutdown();
	return result;
}