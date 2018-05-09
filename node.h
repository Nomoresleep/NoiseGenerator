#pragma once

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
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
    
};

class PropertyBase
{
public:
	virtual void Render() = 0;
};

template <typename T>
class Property : public PropertyBase
{
public:
	Property(T* aValueAddress, T aMin, T aMax)
		: myMin(aMin)
		, myMax(aMax)
		, myValue(aValueAddress) {}

	void Render() override;

	void Set(T aValue) { *myValue = MC_Min(myMax, MC_Max(myMin, aValue)); }
	const T& Get() const { return *myValue; }
	
	T* myValue;
	T myMin, myMax;
};

template <typename T>
static void locRenderDrag(Property<T>* aProperty);

template <>
static void locRenderDrag<f32>(Property<f32>* aProperty)
{
	ImGui::DragFloatProgress("Test Label##awinqwfpi", aProperty->myValue, 0.001f, aProperty->myMin, aProperty->myMax);
}

template <>
static void locRenderDrag<s32>(Property<s32>* aProperty)
{
	ImGui::DragInt("##knawlfn", aProperty->myValue, 1.0f, aProperty->myMin, aProperty->myMax);
}

template <>
static void locRenderDrag<u32>(Property<u32>* aProperty)
{
	s32 propertyValue = (s32)*aProperty->myValue;
	ImGui::DragInt("##knawlfn", &propertyValue, 1.0f, MC_Max(0u, aProperty->myMin), aProperty->myMax);
	*aProperty->myValue = (u32)propertyValue;
}

template <typename T>
void Property<T>::Render() { locRenderDrag(this); }

enum PortType
{
    FloatPort,
    IntPort,
	UIntPort,
};

union PortData
{
    float myFloatData;
    int myIntPortData;
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
    MC_GrowingArray<InputPort*> myConnectedInputs;
    PortData myData;
    const PortType myType;
	MC_Vector2f myPosition;
};

struct InputPort
{
	InputPort(Node* aNode, PortType aPortType, PropertyBase* aPortProperty)
		: myType(aPortType)
        , myNode(aNode)
        , myConnectedPort(nullptr)
		, myProperty(aPortProperty)
    {}

    void Connect(OutputPort* aConnectedPort);
	bool TryConnect(OutputPort* aConnectedPort);

    Node* myNode;
	MC_ScopedPtr<PropertyBase> myProperty;
    const PortType myType;
	MC_Vector2f myPosition;
    OutputPort* myConnectedPort;
};

class Node
{
public:
    Node(int id, const char* name, const MC_Vector2f& pos)
        : myID(id)
        , myLabel(name)
        , myPosition(pos)
        , myOutputs(8)
        , myInputs(8){};

    virtual void OnTraverse(GraphRunnerContext* aGraphRunnerContext) = 0;
    u32 ConnectedInputCount() const;

    const char* myLabel;
    int myID;

    MC_Vector2f myPosition;
    MC_Vector2f mySize;

	MC_GrowingArray<MC_ScopedPtr<OutputPort>> myOutputs;
	MC_GrowingArray<MC_ScopedPtr<InputPort>> myInputs;
protected:
    void AddInputPort(InputPort* anInputPort);
    void AddOutputPort(OutputPort* anOutputPort);
    void CalculateSize();
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
    }
    return IM_COL32(255, 255, 255, 255);
}