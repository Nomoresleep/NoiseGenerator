#pragma once

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
#include "MC_String.h"
#include "MC_ScopedPtr.h"
#include "MC_Vector.h"
#include "MC_Pair.h"

struct InputPort;
class NG_Node;

struct NG_GraphRunnerContext
{
	u32 myNodesTraversed;
    MC_GrowingArray<MC_String> myGeneratedSource;
};

struct NG_Port
{
	enum Type
	{
		FloatPort,
		IntPort,
		UIntPort,
	};

	union Data
	{
		f32 myFloatData;
		s32 myIntPortData;
		u32 myUIntPortData;
	};
};

struct OutputPort
{
    OutputPort(NG_Node* aNode, NG_Port::Type aPortType)
        : myType(aPortType)
        , myNode(aNode)
        , myConnectedInputs(8)
    {};

	NG_Node* myNode;
    const NG_Port::Type myType;
	NG_Port::Data myData;
	MC_Vector2f myPosition;
	MC_GrowingArray<InputPort*> myConnectedInputs;
};

struct InputPort
{
	InputPort(NG_Node* aNode, NG_Port::Type aPortType)
		: myType(aPortType)
        , myNode(aNode)
        , myConnectedPort(nullptr)
    {}

    void Connect(OutputPort* aConnectedPort);
	bool TryConnect(OutputPort* aConnectedPort);

	NG_Node* myNode;
    const NG_Port::Type myType;
	MC_Vector2f myPosition;
    OutputPort* myConnectedPort;
};

class NG_Node
{
public:
	NG_Node()
        : myOutputs(8)
        , myInputs(8){};

    virtual void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const = 0;
    u32 ConnectedInputCount() const;

	MC_GrowingArray<OutputPort*> myOutputs;
	MC_GrowingArray<InputPort*> myInputs;
protected:
    void AddInputPort(InputPort* anInputPort);
    void AddOutputPort(OutputPort* anOutputPort);
};


template <typename Type>
static NG_Port::Type GetPortType();

template<>
static NG_Port::Type GetPortType<f32>() { return NG_Port::FloatPort; }

template<>
static NG_Port::Type GetPortType<s32>() { return NG_Port::IntPort; }

template<>
static NG_Port::Type GetPortType<u32>() { return NG_Port::UIntPort; }