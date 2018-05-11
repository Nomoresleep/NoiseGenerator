#pragma once

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
#include "MC_String.h"
#include "MC_ScopedPtr.h"
#include "MC_Vector.h"
#include "MC_Pair.h"
#include "imgui_custom_widgets.h"

static const f32 NODE_SLOT_RADIUS = 6.0f;
static const MC_Vector2f NODE_PORT_SIZE = MC_Vector2f(2.0f * NODE_SLOT_RADIUS, 2.0f * NODE_SLOT_RADIUS);
static const MC_Vector2f NODE_WINDOW_PADDING = MC_Vector2f(8.0f, 4.0f);
static const f32 NODE_PROPERTY_WIDTH = 120.0f;

struct GraphRunnerContext
{
	u32 myNodesTraversed;
    MC_GrowingArray<MC_String> myGeneratedSource;
};

enum PortType
{
    FloatPort,
    IntPort,
	UIntPort,
};

union PortData
{
    f32 myFloatData;
    s32 myIntPortData;
	u32 myUIntPortData;
};

struct InputPort;
class Node;

struct OutputPort
{
    OutputPort(Node* aNode, PortType aPortType)
        : myType(aPortType)
        , myNode(aNode)
        , myConnectedInputs(8)
    {};

    Node* myNode;
    const PortType myType;
	PortData myData;
	MC_Vector2f myPosition;
	MC_GrowingArray<InputPort*> myConnectedInputs;
};

struct InputPort
{
	InputPort(Node* aNode, PortType aPortType)
		: myType(aPortType)
        , myNode(aNode)
        , myConnectedPort(nullptr)
    {}

    void Connect(OutputPort* aConnectedPort);
	bool TryConnect(OutputPort* aConnectedPort);

    Node* myNode;
    const PortType myType;
	MC_Vector2f myPosition;
    OutputPort* myConnectedPort;
};

class Node
{
public:
    Node()
        : myOutputs(8)
        , myInputs(8){};

    virtual void OnTraverse(GraphRunnerContext* aGraphRunnerContext) const = 0;
    u32 ConnectedInputCount() const;

	MC_GrowingArray<OutputPort*> myOutputs;
	MC_GrowingArray<InputPort*> myInputs;
protected:
    void AddInputPort(InputPort* anInputPort);
    void AddOutputPort(OutputPort* anOutputPort);
};



template <typename Type>
static PortType GetPortType();

template<>
static PortType GetPortType<f32>() { return PortType::FloatPort; }

template<>
static PortType GetPortType<s32>() { return PortType::IntPort; }

template<>
static PortType GetPortType<u32>() { return PortType::UIntPort; }

static ImU32 GetColorFromPortType(PortType aType)
{
    switch (aType)
    {
    case FloatPort:
        return IM_COL32(0, 95, 0, 255);
    case IntPort:
        return IM_COL32(66, 150, 250, 255);
	case UIntPort:
		return IM_COL32(0, 0, 0, 255);
    }
    return IM_COL32(255, 255, 255, 255);
}