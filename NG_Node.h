#pragma once

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
#include "MC_String.h"
#include "MC_ScopedPtr.h"
#include "MC_Vector.h"
#include "MC_Pair.h"

struct NG_InputPort;
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

struct NG_OutputPort
{
	NG_OutputPort(NG_Node* aNode, NG_Port::Type aPortType)
        : myType(aPortType)
        , myNode(aNode)
        , myConnectedInputs(8)
    {};

	~NG_OutputPort();

	NG_Node* myNode;
	NG_Port::Data myData;
	const NG_Port::Type myType;
	MC_GrowingArray<NG_InputPort*> myConnectedInputs;
};

struct NG_InputPort
{
	NG_InputPort(NG_Node* aNode, NG_Port::Type aPortType)
		: myType(aPortType)
        , myNode(aNode)
        , myConnectedPort(nullptr)
    {}

	~NG_InputPort()
	{
		Connect(nullptr);
	}

    void Connect(NG_OutputPort* aConnectedPort);
	bool TryConnect(NG_OutputPort* aConnectedPort);

	NG_Node* myNode;
    NG_OutputPort* myConnectedPort;
	const NG_Port::Type myType;
};

class NG_Node
{
public:
	NG_Node()
        : myOutputs(8)
        , myInputs(8){};

	~NG_Node()
	{
		myOutputs.DeleteAll();
		myInputs.DeleteAll();
	}

    virtual void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const = 0;
    u32 ConnectedInputCount() const;

	MC_GrowingArray<NG_OutputPort*> myOutputs;
	MC_GrowingArray<NG_InputPort*> myInputs;
protected:
    void AddInputPort(NG_InputPort* anInputPort);
    void AddOutputPort(NG_OutputPort* anOutputPort);
};


template <typename Type>
static NG_Port::Type GetPortType();

template<>
static NG_Port::Type GetPortType<f32>() { return NG_Port::FloatPort; }

template<>
static NG_Port::Type GetPortType<s32>() { return NG_Port::IntPort; }

template<>
static NG_Port::Type GetPortType<u32>() { return NG_Port::UIntPort; }