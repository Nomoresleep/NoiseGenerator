#include "imgui_window.h"
#include "imgui_impl_gl3.h"
#include "borderless-window.h"
#include "opengl_context.h"
#include "dialogs.h"
#include "imgui.h"
#include "workspace.h"
#include "Editor_NodeEditor.h"

//dummy translate macro for later maybe?
#define TR(text) text
//dummy keymap macro for later
#define KM(text) text

s32 theOpenglMajorVersion;
s32 theOpenglMinorVersion;
HGLRC theHGLRC; // Global, shared between windows
s32 theWindowIdCounter = 0; // Helps during debugging


void imgui_set_style_params()
{
    ImGuiStyle* style = &ImGui::GetStyle();
    ImVec4* colors = style->Colors;

    style->Alpha = 1.0f;

    colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_CloseButton] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
    colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 1.00f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
}

void imgui_push_disabled_selected(bool disabled) {
	if (disabled) { ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.25); }
}
void imgui_pop_disabled_selected(bool disabled) {
	if (disabled) { ImGui::PopStyleVar(); }
}

bool imgui_window_begin(borderless_window_t* window, const char *title, bool* openContextMenu)
{
	bool show = true;
	imgui_set_style_params();
	bool result = ImGui::Begin(title, &show, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar) && show;
	if (openContextMenu) *openContextMenu = ImGui::IsItemHovered() && ImGui::IsMouseClicked(1);
	return result;
}

void imgui_window_end()
{
	ImGui::End();
}

void imgui_window_context_menu(borderless_window_t* window, bool openContextMenu)
{
	static const char* menuName = "window_context_menu";
	if (openContextMenu)
	{
		ImGui::OpenPopup(menuName);
	}
	if (ImGui::BeginPopup(menuName))
	{
		//TODO:[NoMoreSleep] Is there a possibility to disable selectables other than this tedious workaround? There is a PushItemFlags for disabling in imgui_internal....
		if (ImGui::Selectable(TR("Restore"))) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_RESTORE, 0); }
		{
			imgui_push_disabled_selected(window->maximized);
			if (ImGui::Selectable(TR("Move")) && !window->maximized) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_MOVE, 0); }
			if (ImGui::Selectable(TR("Change Size")) && !window->maximized) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_SIZE, 0); }
			imgui_pop_disabled_selected(window->maximized);
		}
		if (ImGui::Selectable(TR("Minimize"))) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_MINIMIZE, 0); }
		{
			imgui_push_disabled_selected(window->maximized);
			if (ImGui::Selectable(TR("Maximize")) && !window->maximized) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0); }
			imgui_pop_disabled_selected(window->maximized);
		}
		ImGui::Separator();
		if (ImGui::Selectable(TR("Close"))) { PostMessageW(window->hwnd, WM_QUIT, 0, 0); }
		ImGui::EndPopup();
	}
}

void imgui_window_menu_bar(borderless_window_t* window)
{
    bool openNewFileDialog = false;
    bool openExportDialog = false;
	bool openGPUCapabilitiesDialog = false;
	bool openAboutDialog = false;
    bool saveFileDialog = false;
    bool openCommandWindow = false;

	const bool appRunning = theWorkspace != nullptr;
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu(TR("File")))
		{
            openNewFileDialog = ImGui::MenuItem(TR("New"));
			if (ImGui::MenuItem(TR("Open"), KM("Ctrl+O"))) {}
			if (ImGui::BeginMenu(TR("Open Recent")))
			{
				ImGui::EndMenu();
			}
            saveFileDialog = ImGui::MenuItem(TR("Save"), KM("Ctrl+S"), false, appRunning);
            if (ImGui::MenuItem(TR("Save As.."), 0, false, appRunning)) {}
			ImGui::Separator();
            openExportDialog = ImGui::MenuItem(TR("Export"), 0, false, appRunning);
			if (ImGui::MenuItem(TR("Quit"), KM("Alt+F4"))) { PostMessageW(window->hwnd, WM_QUIT, 0, 0); }
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu(TR("Edit")))
		{
			if (ImGui::MenuItem(TR("Undo"), KM("Ctrl+Z"), false, appRunning)) { theWorkspace->myNodeEditor->Undo(); }
			if (ImGui::MenuItem(TR("Redo"), KM("Ctrl+Y"), false, appRunning)) { theWorkspace->myNodeEditor->Redo(); }
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu(TR("Help")))
		{
            openCommandWindow = ImGui::MenuItem(TR("Command Stack"), 0, false, appRunning);
			openGPUCapabilitiesDialog = ImGui::MenuItem(TR("GPU Capabilities"));
			openAboutDialog = ImGui::MenuItem(TR("About"));
			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}

    if (openNewFileDialog)
    {
        ImGui::OpenPopup(theNewFileDialogID);
    }
    if (openExportDialog)
    {
        ImGui::OpenPopup(theExportDialogID);
    }
	if (openGPUCapabilitiesDialog)
	{
		ImGui::OpenPopup(theGPUCapabilitiesDialogID);
	}
	if (openAboutDialog)
	{
		ImGui::OpenPopup(theAboutDialogID);
	}
    if (openCommandWindow)
    {
        ImGui::OpenPopup(theCommandWindowID);
    }
    if (saveFileDialog)
    {
        ImGui::OpenPopup(theSaveFileDialogID);
    }
}

bool imgui_message(borderless_window_t *window, UINT msg, WPARAM wparam, LPARAM lparam)
{
	imgui_window_t *imgui = (imgui_window_t*)window->userdata;
	ImGui::SetCurrentContext(imgui->context);
	
	if (HIWORD(lparam) < 19 && LOWORD(lparam) < window->width - 17) // TODO: Get title bar dimensions from imgui
	{
		if (msg == WM_LBUTTONDOWN  ) { SendMessageW(window->hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);             return true; } // Drag window
		if (msg == WM_LBUTTONDBLCLK) { ShowWindow(window->hwnd, window->maximized ? SW_RESTORE : SW_MAXIMIZE); return true; } // Toggle maximize
	}
	if (msg == WM_PAINT)
	{
		wglMakeCurrent(window->hdc, theHGLRC);
		ImGui_Impl_WinAPI_GL3_NewFrame(window->hwnd, window->width, window->height, window->width, window->height);
		ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
		ImGui::SetNextWindowSize(ImVec2((float)window->width, (float)window->height));
		imgui->func(window, imgui->userdata);
		glViewport(0, 0, window->width, window->height);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		ImGui_Impl_WinAPI_GL3_RenderDrawData(ImGui::GetDrawData());
		SwapBuffers(window->hdc);
		return true;
	}
	if (msg == WM_CLOSE || msg == WM_QUIT)
	{
		ImGui_Impl_WinAPI_GL3_Shutdown();
		ImGui::DestroyContext();
		free(imgui);
		return true;
	}
	
	return ImGui_Impl_WinAPI_GL3_Handle_Message(window->hwnd, msg, wparam, lparam);
}

borderless_window_t * imgui_window_create(LPCWSTR title, int w, int h, imgui_window_func func, void *userdata)
{
	ImGuiContext* previous = ImGui::GetCurrentContext();
    zlgl_LoadWGLFunctions();
	HDC previousDC = wglGetCurrentDC();

	imgui_window_t *imgui = (imgui_window_t*)calloc(1, sizeof(imgui_window_t));
	imgui->func = func;
	imgui->userdata = userdata;
	imgui->id = theWindowIdCounter++;
	borderless_window_t* window = borderless_window_create(title, w, h, imgui_message, imgui);

	if (!theHGLRC)
	{
		if (!(theHGLRC = opengl_create_context(window->hdc, theOpenglMajorVersion, theOpenglMinorVersion)))
			ExitProcess(ERROR_INVALID_HANDLE);
	}
	else
	{
		if (!opengl_set_pixelformat(window->hdc))
			ExitProcess(ERROR_INVALID_HANDLE);
	}

	ImGui::SetCurrentContext((ImGuiContext*)(((imgui_window_t*)window->userdata)->context = ImGui::CreateContext()));
	ImGui_Impl_WinAPI_GL3_Init();
	ImGui::StyleColorsDark();
	ImGui::GetStyle().WindowRounding = 0.0f; // Try to hide remaining 1px row of windows border in the corners which needs to be there to not get other artifacts :(

	ShowWindow(window->hwnd, SW_SHOWDEFAULT);
	UpdateWindow(window->hwnd);

	if (previousDC)
		wglMakeCurrent(previousDC, theHGLRC);
	ImGui::SetCurrentContext(previous);

    window->initialized = true;;

	return window;
}

void imgui_window_init(int openglMajorVersion, int openglMinorVersion)
{
	theOpenglMajorVersion = openglMajorVersion;
	theOpenglMinorVersion = openglMinorVersion;
	borderless_window_register();
}

void imgui_window_shutdown()
{
	opengl_destroy_context(theHGLRC);
	theHGLRC = NULL;
	borderless_window_unregister();
}

int imgui_window_message_loop()
{
	MSG message = {0};
	while (GetMessageW(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}
	return (int)message.wParam;
}