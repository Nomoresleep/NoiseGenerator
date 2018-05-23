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

	MC_String myLabel;

	MC_Vector2f myPosition;
    MC_Vector2f myDeltaPosition;
	MC_Vector2f mySize;

    void CalculateSize();
};

struct Editor_NodeGraphSelection
{
	MC_GrowingArray<Editor_NodeProperties*> myNodes;
	MC_GrowingArray<int*> myConnections;

	void Clear()
	{
		myNodes.RemoveAll();
		myConnections.RemoveAll();
	}
};

void Editor_DisplayProperty(NG_Port::Data& somePortData, NG_Port::Type aPortType);