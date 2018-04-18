static int g_openglMajorVersion;
static int g_openglMinorVersion;
static HGLRC g_hglrc; // Global, shared between windows
static int g_windowIdCounter = 0; // Helps during debugging

struct imgui_window_t;

typedef void (*imgui_window_func)(borderless_window_t *window, void *userdata);

struct imgui_window_t
{
	ImGuiContext *context;
	imgui_window_func func;
	void *userdata;
	int id;
};

void imgui_push_disabled_selected(bool disabled) {
	if (disabled) { ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.25); }
}
void imgui_pop_disabled_selected(bool disabled) {
	if (disabled) { ImGui::PopStyleVar(); }
}
static bool imgui_window_context_menu(borderless_window_t* window)
{
	bool result = true;
	if (ImGui::BeginPopupContextItem("window_context_menu"))
	{
		//TODO:[NoMoreSleep] Is there a possibility to disable selectables other than this tedious workaround? There is a PushItemFlags for disabling in imgui_internal....
		if (ImGui::Selectable("Restore")) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_RESTORE, 0); }
		{
			imgui_push_disabled_selected(window->maximized);
			if (ImGui::Selectable("Move") && !window->maximized) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_MOVE, 0); }
			if (ImGui::Selectable("Change Size") && !window->maximized) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_SIZE, 0); }
			imgui_pop_disabled_selected(window->maximized);
		}
		if (ImGui::Selectable("Minimize")) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_MINIMIZE, 0); }
		{
			imgui_push_disabled_selected(window->maximized);
			if (ImGui::Selectable("Maximize") && !window->maximized) { PostMessage(window->hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0); }
			imgui_pop_disabled_selected(window->maximized);
		}
		ImGui::Separator();
		if (ImGui::Selectable("Close")) { result = false; }
		ImGui::EndPopup();
	}
	return result;
}

bool imgui_window_begin(borderless_window_t* window, const char *title)
{
	bool show = true;
	return ImGui::Begin(title, &show, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse) && imgui_window_context_menu(window) && show;
}

void imgui_window_end()
{
	ImGui::End();
}

static bool imgui_message(borderless_window_t *window, UINT msg, WPARAM wparam, LPARAM lparam)
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
		wglMakeCurrent(window->hdc, g_hglrc);
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
	HDC previousDC = wglGetCurrentDC();

	imgui_window_t *imgui = (imgui_window_t*)calloc(1, sizeof(imgui_window_t));
	imgui->func = func;
	imgui->userdata = userdata;
	imgui->id = g_windowIdCounter++;
	borderless_window_t* window = borderless_window_create(title, w, h, imgui_message, imgui);

	if (!g_hglrc)
	{
		if (!(g_hglrc = opengl_create_context(window->hdc, g_openglMajorVersion, g_openglMinorVersion)))
			ExitProcess(ERROR_INVALID_HANDLE);
		gladLoadGL();
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
		wglMakeCurrent(previousDC, g_hglrc);
	ImGui::SetCurrentContext(previous);

	return window;
}

void imgui_window_init(int openglMajorVersion, int openglMinorVersion)
{
	g_openglMajorVersion = openglMajorVersion;
	g_openglMinorVersion = openglMinorVersion;
	borderless_window_register();
}

void imgui_window_shutdown()
{
	opengl_destroy_context(g_hglrc);
	g_hglrc = NULL;
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