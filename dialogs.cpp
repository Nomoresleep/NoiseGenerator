#include "dialogs.h"
#include "workspace.h"
#include "imgui.h"

void ShowNewFileDialog()
{
	static s32 width = 1024;
	static s32 height = 1024;
	ImGui::DragInt("Width", &width);
	ImGui::DragInt("Height", &height);
	if (ImGui::Button("Create"))
	{
		if (theWorkspace)
			delete theWorkspace;

		theWorkspace = new Workspace(width, height);
		ImGui::CloseCurrentPopup();
	}
}

void ShowExportDialog()
{
	const char* extensions[ExportExtensionCount] = {
		"png",
		"bmp",
		"tga",
		"jpg",
		"hdr",
	};
	static s32 currentExtension = 0;
	ImGui::Combo("Extension", &currentExtension, extensions, ExportExtensionCount);
	if (ImGui::Button("Export"))
	{
		theWorkspace->Export((ExportExtension)currentExtension);
		ImGui::CloseCurrentPopup();
	}
}

void ShowGPUCapabilitiesDialog()
{
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* slVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	ImGui::Text("Running OpenGL %d.%d", major, minor);
	ImGui::Text("Vendor: %s", vendor);
	ImGui::Text("Renderer: %s", renderer);
	ImGui::Text("Shading Language Version: %s", slVersion);

	ImGui::Separator();

	GLint maxTextureSize;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
	ImGui::Text("Max. Texture Size: %d", maxTextureSize);

	GLint maxComputeWorkGroupInvocations;
	glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &maxComputeWorkGroupInvocations);
	ImGui::Text("Max. Compute Group Invocations: %d", maxComputeWorkGroupInvocations);
	
	GLint maxComputeWorkGroupCount[3];
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &maxComputeWorkGroupCount[0]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &maxComputeWorkGroupCount[1]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &maxComputeWorkGroupCount[2]);
	ImGui::Text("Max. Compute Work Group Count: [%d, %d, %d]", 
		maxComputeWorkGroupCount[0], 
		maxComputeWorkGroupCount[1], 
		maxComputeWorkGroupCount[2]);

	GLint maxComputeWorkGroupSize[3];
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &maxComputeWorkGroupSize[0]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &maxComputeWorkGroupSize[1]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &maxComputeWorkGroupSize[2]);
	ImGui::Text("Max. Compute Work Group Size: [%d, %d, %d]",
		maxComputeWorkGroupSize[0],
		maxComputeWorkGroupSize[1],
		maxComputeWorkGroupSize[2]);
}

void ShowAboutDialog()
{
	ImGui::Text("Copyright Nomoresleep - 2018");
}