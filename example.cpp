#include <windows.h>
#include <random>
#include "MC_IniFile.h"
#include "borderless-window.h"

#include "opengl_context.h"
#include "imgui/imgui.h"
#include "imgui/imgui_window.h"
#include "exporter.h"

#include "opengl_context.h"
#include "workspace.h"
#include "dialogs.h"
#include "filedialog.h"
#include "NG_GraphRunner.h"
#include "NG_NodeGraph.h"
#include "Editor_NodeEditor.h"
#include "Editor_NodeTools.h"
#include "MCC_Json.h"

#pragma comment(lib, "MCommon.lib")
#pragma comment(lib, "Editor.lib")
#pragma comment(lib, "Dbghelp.lib")

static f32 zoom = 1.0f;
static const f32 zoom_min = 0.2f;
static const f32 zoom_max = 20.0f;

static const char* thePathToIni = "NoiseGen.ini";

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

static void SaveWorkspace(void* someUserData, const char* aFilename)
{
    Workspace* workspace = (Workspace*)someUserData;
    MF_File file(aFilename, MF_File::OPEN_WRITE);
    MC_Json::Object workspaceObject;
    workspaceObject["ImageSize"] = workspace->myImageSize;
	MC_Json::Array nodeGraphArray;
	const MC_GrowingArray<Editor_NodeProperties*> props = theWorkspace->myNodeEditor->GetNodeProperties();
	for (const Editor_NodeProperties* prop : props)
	{
		MC_Json::Object jsonNode;
		jsonNode["UID"] = prop->myNode->myUID;
		jsonNode["ClassName"] = prop->myLabel;
		jsonNode["Position"] = prop->myPosition;

		NG_Node* node = prop->myNode;
		MC_Json::Array jsonInputs;
		for (s32 inIdx = 0; inIdx < node->myInputs.Count(); ++inIdx)
		{
			MC_Json::Object inputObject;
			inputObject["ConnectedNode"] = node->myInputs[inIdx]->myConnectedPort ? node->myInputs[inIdx]->myConnectedPort->myNode->myUID : MC_Json();
			inputObject["PortIndex"] = node->myInputs[inIdx]->myConnectedPort ? node->myInputs[inIdx]->myConnectedPort->myNode->myOutputs.Find(node->myInputs[inIdx]->myConnectedPort) : MC_Json();
            inputObject["PortData"] = MC_String::ToBase64((const u8*)&node->myInputs[inIdx]->myData.myValue, sizeof(NG_Port::Data::Value));
			jsonInputs.Add(inputObject);
		}
		jsonNode["InputConnections"] = jsonInputs;
		nodeGraphArray.Add(jsonNode);
	}
	workspaceObject["NodeGraph"] = nodeGraphArray;
    MC_Json jsonObject = workspaceObject;
    MC_String jsonString = jsonObject.Serialize();
    file.WriteASCIIZ(jsonString);
    file.Close();
}

static void LoadWorkspace(const char* aFilename)
{
	MC_Json workspaceObject = MC_Json::FromFile(aFilename);
	MC_Vector3i imageSize;
	if (workspaceObject.GetElement("ImageSize", imageSize))
	{
		if (theWorkspace)
			delete theWorkspace;

		theWorkspace = new Workspace(imageSize.x, imageSize.y);

		MC_Json nodeGraphObject;
		workspaceObject.GetJsonElement("NodeGraph", nodeGraphObject);
		MC_Json::Array nodeGraphArray = nodeGraphObject.GetArray();
        MC_HashMap<s32, s32> oldToNewUID;
		for (const MC_Json& node : nodeGraphArray)
		{
			MC_String className;
			assert(node.GetElement("ClassName", className));
			MC_Vector2f position;
			assert(node.GetElement("Position", position));
			NG_Node* newNode = NG_NodeModule::Create(className);
			theWorkspace->myNodeEditor->CreateNode(newNode, className, position);

            s32 oldNodeUID = -1;
            assert(node.GetElement("UID", oldNodeUID));
            oldToNewUID[oldNodeUID] = newNode->myUID;
		}

        struct NodeByID
        {
            static bool Equals(const NG_Node* aNode, s32 aUID) { return aNode->myUID == aUID; }
        };

		for (const MC_Json& nodeObject : nodeGraphArray)
		{
			MC_Json inputConnections;
            nodeObject.GetJsonElement("InputConnections", inputConnections);
            s32 nodeUID = -1;
            nodeObject.GetElement("UID", nodeUID);
            nodeUID = oldToNewUID[nodeUID];
            s32 nodeIdx = theWorkspace->myNodeGraph->GetNodes().Find2<NodeByID>(nodeUID);
            NG_Node* node = theWorkspace->myNodeGraph->GetNodes()[nodeIdx];
			MC_Json::Array inputConnectionArray = inputConnections.GetArray();
            s32 INPUT_CHANGE = 0;
			for (MC_Json& connection : inputConnectionArray)
			{
				s32 connectedNodeUID = -1, portIndex = -1;
                MC_String portData;
				connection.GetElement("ConnectedNode", connectedNodeUID);
				connection.GetElement("PortIndex", portIndex);
                connection.GetElement("PortData", portData);
                void* portDataBuffer = MC_String::FromBase64(portData);
                memcpy(&node->myInputs[INPUT_CHANGE]->myData.myValue, portDataBuffer, sizeof(NG_Port::Data::Value));
                delete portDataBuffer;

                if (connectedNodeUID == -1 || portIndex == -1)
                    continue;
                connectedNodeUID = oldToNewUID[connectedNodeUID];
                nodeIdx = theWorkspace->myNodeGraph->GetNodes().Find2<NodeByID>(connectedNodeUID);
                NG_Node* connectedNode = theWorkspace->myNodeGraph->GetNodes()[nodeIdx];
                node->myInputs[INPUT_CHANGE++]->Connect(connectedNode->myOutputs[portIndex]);
			}
		}
	}
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

	bool openOpenFile = true;
	if (ImGui::BeginPopupModal(theOpenDialogID, &openOpenFile, modalFlags))
	{
		LoadWorkspace(".naps");
		ImGui::CloseCurrentPopup();
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

    bool commandWindowOpen = true;
    if (theWorkspace && ImGui::BeginPopupModal(theCommandWindowID, &commandWindowOpen, modalFlags))
    {
        theWorkspace->myNodeEditor->ShowCommandDialogHelper();

        ImGui::EndPopup();
    }

    static FileDialog* fileDialog = nullptr;
    if (ImGui::IsPopupOpen(theSaveFileDialogID))
    {
        if (!fileDialog)
            fileDialog = new FileDialog(SaveWorkspace, theWorkspace);

        fileDialog->Show();
    }
    else if (fileDialog)
    {
        delete fileDialog;
        fileDialog = nullptr;
    }
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
		if (ImGui::GetIO().KeyCtrl)
		{
			if (ImGui::IsKeyPressed('Z'))
			{
				theWorkspace->myNodeEditor->Undo();
			}
			else if (ImGui::IsKeyPressed('Y'))
			{
				theWorkspace->myNodeEditor->Redo();
			}
		}
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
    RegisterCommonExporters();

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