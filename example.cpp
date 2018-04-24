#include <windows.h>
#include <random>
#include "borderless-window.h"
#include "opengl_context.h"

#include "glzl_core.hpp"
#include "imgui.h"
#include "imgui_impl_gl3.h"
#include "imgui_window.cpp"

#include "nodegraph.h"

GLuint computeProgram;
GLuint textureID;
const i32 width = 1024;
const i32 height = 1024;

static const char* computeShaderString =
"#version 430\n"
"layout(local_size_x = 8, local_size_y = 8) in;\n"
"layout(rg32f, binding = 0) uniform image2D img_output;\n"
"layout(std430, binding = 0) buffer permutationBuffer\n"
"{\n"
"int myData[512];\n"
"}permBuffer;\n"
"layout(std430, binding = 1) buffer permutationBuffer12\n"
"{\n"
"int myData[512];\n"
"}permBuffer12;\n"
"const float GRAD_X[] = \n"
"{\n"
"	1.0, -1.0, 1.0, -1.0,\n"
"	1.0, -1.0, 1.0, -1.0,\n"
"	0.0, 0.0, 0.0, 0.0\n"
"};\n"
"const float GRAD_Y[] = \n"
"{\n"
"	1.0, 1.0, -1.0, -1.0,\n"
"	0.0, 0.0, 0.0, 0.0,\n"
"	1.0, -1.0, 1.0, -1.0\n"
"};\n"
"const float GRAD_Z[] = \n"
"{\n"
"	0.0, 0.0, 0.0, 0.0,\n"
"	1.0, 1.0, -1.0, -1.0,\n"
"	1.0, 1.0, -1.0, -1.0\n"
"};\n"
"float GradCoord2D(int x, int y, float xd, float yd){\n"
"int lutPos = permBuffer12.myData[(x & 0xff) + permBuffer.myData[(y & 0xff)]];\n"
"return xd*GRAD_X[lutPos] + yd*GRAD_Y[lutPos];\n"
"}\n"
"void main(){\n"
"ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);\n"
"float x = (pixel_coords.x / 1024.0) * 16.0;\n"
"float y = (pixel_coords.y / 1024.0) * 16.0;\n"
"int x0 = int(floor(x));\n"
"int y0 = int(floor(y));\n"
"int x1 = x0 + 1;\n"
"int y1 = y0 + 1;\n"
"float xs = fract(x);\n"
"float ys = fract(y);\n"
"float xd0 = xs;\n"
"float yd0 = ys;\n"
"float xd1 = xd0 - 1.0;\n"
"float yd1 = yd0 - 1.0;\n"
"float xf0 = mix(GradCoord2D(x0, y0, xd0, yd0), GradCoord2D(x1, y0, xd1, yd0), xs);\n"
"float xf1 = mix(GradCoord2D(x0, y1, xd0, yd1), GradCoord2D(x1, y1, xd1, yd1), xs);\n"
"float perlin = mix(xf0, xf1, ys);\n"
"vec4 pixel_value = vec4(perlin, 0.0, 0.0, 1.0);\n"
"imageStore(img_output, pixel_coords, pixel_value);\n"
"}";

static f32 zoom = 1.0f;
static const f32 zoom_min = 0.2f;
static const f32 zoom_max = 20.0f;

static f32 frequency = 1.0f;
static const f32 frequency_min = 0.01f;
static const f32 frequency_max = 20.0f;

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

#if 1

	static f32 freq = 2.0f;
	ImGui::Columns(3);
    {
        if (ImGui::CollapsingHeader("Texture Properties", ImGuiTreeNodeFlags_DefaultOpen))
        {

        }
        if (ImGui::CollapsingHeader("Noise Properties", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::BeginChild("Properties");
            ImGui::Columns(2);
            ImGui::PushItemWidth(100.0f);
            ImGui::Text("Name");
            ImGui::NextColumn();
            ImGui::Text("Value");
            ImGui::Columns(1);
            ImGui::Separator();
            ImGui::Columns(2);
            ImGui::PushItemWidth(100.0f);
            ImGui::Text("frequency##0");
            ImGui::Text("frequency##1");
            ImGui::Text("frequency##2");
            ImGui::NextColumn();
            ImGui::PushItemWidth(-1.0f);
            ImGui::SliderFloat("frequency##3", &zoom, zoom_min, zoom_max);
            ImGui::SliderFloat("frequency##4", &zoom, zoom_min, zoom_max);
            ImGui::SliderFloat("frequency##5", &zoom, zoom_min, zoom_max);
            ImGui::Columns(1);
            ImGui::EndChild();
        }
    }
    ImGui::NextColumn();
    {
        if (ImGui::Button("-", ImVec2(ImGui::GetTextLineHeightWithSpacing(), ImGui::GetTextLineHeightWithSpacing()))) zoom = min(zoom_max, max(zoom_min, zoom - 0.1f));
        ImGui::SameLine();
        ImGui::SliderFloat("zoom_slider", &zoom, zoom_min, zoom_max);
        ImGui::SameLine();
        if (ImGui::Button("+")) zoom = min(zoom_max, max(zoom_min, zoom + 0.1f));
        ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0, 0, 0, 1));
        ImGui::BeginChild("2", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        if (ImGui::IsItemHovered())
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
    ImGui::NextColumn();
    {
        ImGui::BeginChild("NodeGraph", ImVec2(ImGui::GetWindowContentRegionWidth(), (ImGui::GetWindowContentRegionMax().y - ImGui::GetWindowContentRegionMin().y) * 0.5f));
        bool t = true;
        ShowExampleAppCustomNodeGraph(&t);
        ImGui::EndChild();
    }

	{
		glUseProgram(computeProgram);
		glDispatchCompute((GLuint)width / 8, (GLuint)height / 8, 1);
		glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	}

#else
    ImGui::Begin("Style Editor");
    ImGui::ShowStyleEditor();
    ImGui::End();

	ImGui::ShowDemoWindow();
#endif
	imgui_window_end();
}

static void app_init_resources()
{
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RG32F, width, height, 0, GL_RG, GL_FLOAT, 0);
	glBindImageTexture(0, textureID, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RG32F);

	GLuint computeShader = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(computeShader, 1, &computeShaderString, 0);
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
	imgui_window_create(L"GLFastNoise", 1200, 1200, app_main_loop, NULL);

	app_init_resources();

	i32 result = imgui_window_message_loop();
	imgui_window_shutdown();
	return result;
}