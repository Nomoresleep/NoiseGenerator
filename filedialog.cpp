#include "filedialog.h"
#include "MCommon/mf_file.h"
#include "MCommon/MC_SystemPaths.h"
#include "dialogs.h"
#include "imgui/imgui.h"
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")

void FileDialog::Show()
{
    bool stayOpen = true;
    ImGui::SetNextWindowSize(ImVec2(750, 400));
    if (ImGui::BeginPopupModal(theSaveFileDialogID, &stayOpen, ImGuiWindowFlags_NoResize| ImGuiWindowFlags_NoScrollbar))
    {
        static char pathBuffer[MAX_PATH_LENGTH];
        strncpy(pathBuffer, myCurrentDir.GetBuffer(), MC_Min((u32)myCurrentDir.GetLength(), sizeof(pathBuffer)));
        ImGui::PushItemWidth(-1.0f);
        if (ImGui::InputText("path", pathBuffer, sizeof(pathBuffer), ImGuiInputTextFlags_EnterReturnsTrue))
        {
            myCurrentDir = pathBuffer;
            MF_File::GetDir(myCurrentDir.GetBuffer(), &myCurrentDirData);
        }
        ImGui::PopItemWidth();

        ImGui::BeginChild("FileExplorer", ImVec2(ImGui::GetWindowContentRegionWidth(), 320), true);
        MF_GetDirEntryData* dirEntry = myCurrentDirData.myFirstEntry; 
        
        ImGui::Columns(4);
        ImGui::Separator();
        ImGui::Text(""); ImGui::NextColumn();
        ImGui::Text("Name"); ImGui::NextColumn();
        ImGui::Text("Size"); ImGui::NextColumn();
        ImGui::Text("Last Edited"); ImGui::NextColumn();
        ImGui::Separator();
        static s32 selected = -1;
        s32 index = 0;

		ImGuiSelectableFlags selectableFlags = ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_DontClosePopups | ImGuiSelectableFlags_AllowDoubleClick;
		if (ImGui::Selectable("D##-1", selected == index, selectableFlags) && ImGui::IsMouseDoubleClicked(0))
        {
            PathAppendA(myCurrentDir.GetBuffer(), "..");
            MF_File::GetDir(myCurrentDir.GetBuffer(), &myCurrentDirData);
        }
        bool hovered = ImGui::IsItemHovered();
        ImGui::NextColumn();
        ImGui::Text(".."); ImGui::NextColumn();
        ImGui::Text(".."); ImGui::NextColumn();
        ImGui::Text(".."); ImGui::NextColumn();

        while(dirEntry)
        {
            if (ImGui::Selectable(dirEntry->myIsDirectoryFlag ? MC_Strfmt<16>("D##%d", index) : MC_Strfmt<16>("F##%d", index), selected == index, selectableFlags) && ImGui::IsMouseDoubleClicked(0))
            {
                if (dirEntry->myIsDirectoryFlag)
                {
                    PathAppendA(myCurrentDir.GetBuffer(), dirEntry->myName);
                    MF_File::GetDir(myCurrentDir.GetBuffer(), &myCurrentDirData);
                }
            }
            bool hovered = ImGui::IsItemHovered();
            ImGui::NextColumn();
            ImGui::Text(dirEntry->myName); ImGui::NextColumn();
            ImGui::Text("%d", dirEntry->myFileSize); ImGui::NextColumn();

			MF_FileDatTime dateTime;
			MF_File::ConvertCompressedDateTimeToExtendedForm(dirEntry->myFileDateTime, dateTime);
			ImGui::Text("%d-%d-%d", dateTime.myYear, dateTime.myMonth, dateTime.myDay);
			ImGui::SameLine(ImGui::CalcTextSize("0000-00-00").x, 8.0f);
			ImGui::Text("%d:%d:%d", dateTime.myHour, dateTime.myMinute, dateTime.mySecond); ImGui::NextColumn();
            
            dirEntry = dirEntry->myNextPtr;
            index++;
        }
        ImGui::Columns(1);
        ImGui::EndChild();
        //TODO: what size is appropriate?
        static char filename[MAX_PATH_LENGTH];
        bool save = false;
        save |= ImGui::InputText("Filename", filename, sizeof(filename), ImGuiInputTextFlags_EnterReturnsTrue);
        ImGui::SameLine();
        save |= ImGui::Button("Save");

        if (save)
        {
            char buffer[MAX_PATH_LENGTH];
            MF_File::ReplaceExtension(buffer, filename, "ngen");
            MF_File file(buffer, MF_File::OPEN_WRITE);
            file.Write(MC_Vector3f(1, 2, 3));
            file.Close();
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}