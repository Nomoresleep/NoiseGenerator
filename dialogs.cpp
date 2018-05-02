#include "dialogs.h"
#include "workspace.h"
#include "imgui.h"

void ShowNewFileDialog()
{
	static i32 width = 1024;
	static i32 height = 1024;
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
	static i32 currentExtension = 0;
	ImGui::Combo("Extension", &currentExtension, extensions, ExportExtensionCount);
	if (ImGui::Button("Export"))
	{
		theWorkspace->Export((ExportExtension)currentExtension);
		ImGui::CloseCurrentPopup();
	}
}

void ShowGPUCapabilitiesDialog()
{

}

void ShowAboutDialog()
{

}