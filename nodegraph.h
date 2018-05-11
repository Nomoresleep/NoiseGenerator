#pragma once 

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
#include "MC_StackList.h"
#include "MC_ScopedPtr.h"
#include "MC_Vector.h"
#include "MC_HashMap.h"
#include "MC_Pair.h"
#include "imgui.h"
#include "node.h"
#include "nodemodule.h"
#include "nodelibrary.h"

static OutputPort* g_draggedOutput = nullptr;

static void locDrawBezierCurve(ImDrawList* aDrawList, MC_Vector2f aP0, MC_Vector2f aP1, ImU32 aColor)
{
    static const f32 CURVE_THICKNESS = 2.0f;
    float xdist = MC_Min(50.0f, aP1.x - aP0.x);
    aDrawList->AddBezierCurve(aP0, aP0 + MC_Vector2f(xdist, 0), aP1 + MC_Vector2f(-xdist, 0), aP1, IM_COL32(100, 100, 100, 255), CURVE_THICKNESS + 1.5f);
    aDrawList->AddBezierCurve(aP0, aP0 + MC_Vector2f(xdist, 0), aP1 + MC_Vector2f(-xdist, 0), aP1, aColor, CURVE_THICKNESS);
}

static void locDrawPort(ImDrawList* aDrawList, MC_Vector2f aPortPos, ImU32 aColor)
{
	//aDrawList->AddCircleFilled(aPortPos + NODE_PORT_SIZE * 0.5f, NODE_PORT_SIZE.x * 0.5f, aColor);
	//aDrawList->AddCircle(aPortPos + NODE_PORT_SIZE * 0.5f, NODE_PORT_SIZE.x * 0.5f, IM_COL32(200, 200, 200, 255));
    aDrawList->AddRectFilled(aPortPos, aPortPos + NODE_PORT_SIZE, aColor);
    aDrawList->AddRect(aPortPos, aPortPos + NODE_PORT_SIZE, IM_COL32(200, 200, 200, 255), 0.0f, ImDrawCornerFlags_All, 1.0f);
}

static void locDisplayWarning(const char* aWarningMessage)
{
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(200, 170, 50, 255));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
	ImGui::BeginTooltip();
	ImGui::Text(aWarningMessage);
	ImGui::EndTooltip();
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
}

class NodeEditor;

class NodeGraph
{
	typedef MC_GrowingArray<MC_ScopedPtr<Node>> NodeList;
public:
	NodeGraph();

	bool ContainsNodeOfName(const char* aNodeName);
	static bool IsCyclicFromNode(Node* aNode);

	void AddNode(Node* aNewNode, const char* aNodeName, const MC_Vector2f& aPosition);
	void SetEditor(NodeEditor* anEditor) { myEditor = anEditor; }

	const NodeList& GetNodes() const { return myNodes; };
private:
	NodeEditor* myEditor;
	MC_GrowingArray<MC_ScopedPtr<Node>> myNodes;
};
