#include <windows.h>
#include <random>
#include "MCommon/mf_file.h"
#include "borderless-window.h"
#include "opengl_context.h"

#include "glzl_core.hpp"
#include "imgui.h"
#include "imgui_impl_gl3.h"
#include "imgui_window.cpp"

#include "nodegraph.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#pragma comment(lib, "MCommon.lib")
#pragma comment(lib, "Dbghelp.lib")

GLuint computeProgram;
GLuint textureID;
const i32 width = 1024;
const i32 height = 1024;

static const char* computeShaderString =
"layout(local_size_x = 8, local_size_y = 8) in;\n"
"layout(rgba32f, binding = 0) uniform image2D img_output;\n"
"void main(){\n"
"ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);\n"
"float x = (pixel_coords.x / 1024.0) * 16.0;\n"
"float y = (pixel_coords.y / 1024.0) * 16.0;\n"
"float perlin = PerlinNoise2D(x,y);\n"
"vec4 pixel_value = vec4(perlin, perlin, perlin, 1.0);\n"
"imageStore(img_output, pixel_coords, pixel_value);\n"
"}";

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
	ImVec2 imageSize = { zoom * (f32)width, zoom * (f32)height };

	//NOTE:[NoMoreSleep] Button necessary for Item activiation query
	ImGui::ImageButton((void*)textureID, imageSize, ImVec2(0, 0), ImVec2(1, 1), 0);

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

static void app_main_loop(borderless_window_t *window, void * /*userdata*/)
{
    if (!window->initialized)
        return;

	static bool openContextMenu = false;
	if (!imgui_window_begin(window, "GLFastNoise", &openContextMenu))
	{
		borderless_window_close_all(window);
		PostQuitMessage(0);
	}
	imgui_window_menu_bar(window);
	imgui_window_context_menu(window, openContextMenu);
	
	if(!theNodeGraph)
		theNodeGraph = new NodeGraph();

	ImGui::Columns(2);
	locShowTexturePreview();
    ImGui::NextColumn();
	ShowNodeGraph(theNodeGraph);

	{
		glUseProgram(computeProgram);
		glDispatchCompute((GLuint)width / 8, (GLuint)height / 8, 1);
		glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	}

	if (ImGui::GetIO().KeyCtrl && ImGui::GetIO().KeysDown['S'])
	{
		glBindTexture(GL_TEXTURE_2D, textureID);
		MC_ScopedArray<char> img = new char[width * height * 4 * sizeof(u8)];
		glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
		stbi_write_png("test.png", width, height, 4, img.Data(), 0);
	}

	imgui_window_end();
}

static void app_init_resources()
{
	MF_File perlinNoiseFile(locPerlinNoise2DSource);
	MC_ScopedArray<char> perlinSource = new char[perlinNoiseFile.GetSize() + 1];
	perlinNoiseFile.Read(perlinSource.Data(), perlinNoiseFile.GetSize());
	perlinSource[perlinNoiseFile.GetSize()] = '\0';

	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, 0);
	glBindImageTexture(0, textureID, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

	const char* strs[] = { perlinSource.Data(), computeShaderString };

	GLuint computeShader = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(computeShader, 2, strs, 0);
	glCompileShader(computeShader);
	GLint logLength = 0;
	glGetShaderiv(computeShader, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 1)
	{
		char* log = new char[logLength];
		GLsizei length;
		glGetShaderInfoLog(computeShader, logLength, &length, log);
		OutputDebugStringA(log);
		delete[] log;
		return;
	}
	computeProgram = glCreateProgram();
	glAttachShader(computeProgram, computeShader);
	glLinkProgram(computeProgram);

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
	imgui_window_create(L"GLFastNoise", 1920, 1000, app_main_loop, NULL);

	app_init_resources();

	i32 result = imgui_window_message_loop();
	imgui_window_shutdown();
	return result;
}