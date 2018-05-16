#include "Editor_NodeTools.h"
#include "Editor_NodeEditor.h"
#include "imgui/imgui_custom_widgets.h"


void Editor_NodeProperties::CalculateSize()
{
    MC_Vector2f textSize = ImGui::CalcTextSize(myLabel);
    mySize = MC_Vector2f(MC_Max(textSize.x, NODE_PROPERTY_WIDTH) + 2.0f * NODE_WINDOW_PADDING.x, textSize.y + 2.0f * NODE_WINDOW_PADDING.y);
    mySize.y += (myNode->myInputs.Count() + myNode->myOutputs.Count()) * ImGui::GetItemsLineHeightWithSpacing() + ImGui::GetStyle().ItemSpacing.y;
}

void Editor_DisplayProperty(NG_Port::Data& somePortData, NG_Port::Type aPortType)
{
    switch (aPortType)
    {
    case NG_Port::FloatPort:
    {
        ImGui::DragFloatProgress("portData", &somePortData.myValue.myFloat, 0.01f);
    }break;
    case NG_Port::Vec2Port:
    {
        ImGui::DragFloat2("portData", &somePortData.myValue.myVec2.x, 0.01f);
    }break;
    }
}