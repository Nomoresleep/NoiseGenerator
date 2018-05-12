#pragma once

#include "MC_Base.h"
#include "glzl_core.hpp"

extern s32 theOpenglMajorVersion;
extern s32 theOpenglMinorVersion;
extern HGLRC theHGLRC; // Global, shared between windows
extern s32 theWindowIdCounter; // Helps during debugging

struct borderless_window_t;
struct ImGuiContext;
struct ImGuiStyle;

typedef void (*imgui_window_func)(borderless_window_t *window, void *userdata);

struct imgui_window_t
{
	ImGuiContext *context;
	imgui_window_func func;
	void *userdata;
	int id;
};

bool imgui_window_begin(borderless_window_t* window, const char *title, bool* openContextMenu);
void imgui_window_end();

void imgui_window_context_menu(borderless_window_t* window, bool openContextMenu);

void imgui_window_menu_bar(borderless_window_t* window);

bool imgui_message(borderless_window_t *window, UINT msg, WPARAM wparam, LPARAM lparam);

borderless_window_t * imgui_window_create(LPCWSTR title, int w, int h, imgui_window_func func, void *userdata);

void imgui_window_init(int openglMajorVersion, int openglMinorVersion);

void imgui_window_shutdown();

int imgui_window_message_loop();