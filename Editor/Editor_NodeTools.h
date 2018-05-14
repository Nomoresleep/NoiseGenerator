#pragma once

#include "NG_Node.h"


struct Editor_NodeProperties
{
    Editor_NodeProperties(NG_Node* aNode, const char* aLabel, const MC_Vector2f& aPosition)
        : myNode(aNode)
        , myLabel(aLabel)
        , myPosition(aPosition)
        , myDeltaPosition(0, 0)
	{
		CalculateSize();
	};

	NG_Node* myNode;

	const char* myLabel;

	MC_Vector2f myPosition;
    MC_Vector2f myDeltaPosition;
	MC_Vector2f mySize;

	void CalculateSize()
	{
		MC_Vector2f textSize = ImGui::CalcTextSize(myLabel);
		mySize = MC_Vector2f(MC_Max(textSize.x, NODE_PROPERTY_WIDTH) + 2.0f * NODE_WINDOW_PADDING.x, textSize.y + 2.0f * NODE_WINDOW_PADDING.y);
		mySize.y += (myNode->myInputs.Count() + myNode->myOutputs.Count()) * ImGui::GetItemsLineHeightWithSpacing() + ImGui::GetStyle().ItemSpacing.y;
	}
};