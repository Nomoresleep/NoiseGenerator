#include "filedialog.h"
#include "MCommon/mf_file.h"
#include "dialogs.h"
#include "imgui.h"

void ShowFileDialog()
{
    bool stayOpen = true;
    static MC_String dir = "";
    ImGui::SetNextWindowSize(ImVec2(500, 200));
    if (ImGui::BeginPopupModal(theSaveFileDialogID, &stayOpen, ImGuiWindowFlags_ResizeFromAnySide))
    {
        MF_GetDirData dirData;
        MF_File::GetDir(dir, &dirData);

        MF_GetDirEntryData* dirEntry = dirData.myFirstEntry; 
        
        ImGui::Columns(4); // 4-ways, with border
        ImGui::Separator();
        ImGui::Text(""); ImGui::NextColumn();
        ImGui::Text("Name"); ImGui::NextColumn();
        ImGui::Text("Size"); ImGui::NextColumn();
        ImGui::Text("Last Edited"); ImGui::NextColumn();
        ImGui::Separator();
        static s32 selected = -1;
        s32 index = 0;


        if (ImGui::Selectable("D##-1", selected == index, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_DontClosePopups) && ImGui::IsMouseDoubleClicked(0))
        {
            if (dirEntry->myIsDirectoryFlag)
                dir += "../";
        }
        bool hovered = ImGui::IsItemHovered();
        ImGui::NextColumn();
        ImGui::Text(".."); ImGui::NextColumn();
        ImGui::Text(".."); ImGui::NextColumn();
        ImGui::Text(".."); ImGui::NextColumn();

        while(dirEntry)
        {
            if (ImGui::Selectable(dirEntry->myIsDirectoryFlag ? MC_Strfmt<16>("D##%d", index) : MC_Strfmt<16>("F##%d", index), selected == index, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_DontClosePopups) && ImGui::IsMouseDoubleClicked(0))
            {
                if(dirEntry->myIsDirectoryFlag)
                    dir += dirEntry->myName + MC_String("/");
            }
            bool hovered = ImGui::IsItemHovered();
            ImGui::NextColumn();
            ImGui::Text(dirEntry->myName); ImGui::NextColumn();
            ImGui::Text("%d", dirEntry->myFileSize); ImGui::NextColumn();
            ImGui::Text("%d", dirEntry->myFileDateTime); ImGui::NextColumn();
            
            dirEntry = dirEntry->myNextPtr;
            index++;
        }
        ImGui::Columns(1);
        ImGui::Separator();

        ImGui::EndPopup();
    }
}