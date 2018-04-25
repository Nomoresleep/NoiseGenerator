#pragma once

#include "types.h"

struct borderless_window_t;

typedef bool (*message_handler)(borderless_window_t *data, UINT msg, WPARAM wparam, LPARAM lparam);

struct borderless_window_t
{
	HWND hwnd;
	HDC hdc;

	u32 width;
	u32 height;

	bool minimized;
	bool maximized;
	bool composition_enabled;
	bool painting;
    bool initialized;

    RECT tile_restore_rect;

	message_handler handler;
	void* userdata;
};

void borderless_window_register();
void borderless_window_unregister();

borderless_window_t* borderless_window_create(LPCWSTR title, i32 width, i32 height, message_handler handler, void* userdata);
void borderless_window_close_all(borderless_window_t *root);
void borderless_window_close(borderless_window_t *window);