#pragma once

#include "NG_NodeGraph.h"
#include "MC_GrowingArray.h"
#include "imgui/imgui.h"

static const f32 NODE_SLOT_RADIUS = 6.0f;
static const MC_Vector2f NODE_PORT_SIZE = MC_Vector2f(2.0f * NODE_SLOT_RADIUS, 2.0f * NODE_SLOT_RADIUS);
static const MC_Vector2f NODE_WINDOW_PADDING = MC_Vector2f(8.0f, 4.0f);
static const f32 NODE_PROPERTY_WIDTH = 120.0f;

struct Editor_NodeProperties;

static ImU32 GetColorFromPortType(NG_Port::Type aType)
{
	switch (aType)
	{
	case NG_Port::FloatPort:
		return IM_COL32(0, 95, 0, 255);
	case NG_Port::IntPort:
		return IM_COL32(66, 150, 250, 255);
	case NG_Port::UIntPort:
		return IM_COL32(0, 0, 0, 255);
	}
	return IM_COL32(255, 255, 255, 255);
}

class Editor_NodeEditor : public NG_NodeGraphChangeListener
{
public:
	Editor_NodeEditor(NG_NodeGraph* aGraph)
		: myGraph(aGraph) {};
	void Display();

	void OnNodeAdded(NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition) override;
	void OnNodeRemoved(NG_Node* aNode) override;
private:

	MC_GrowingArray<Editor_NodeProperties*> myNodeRenderer;

	NG_NodeGraph* myGraph;
};