#pragma once 

#include "node.h"
#include "nodemodule.h"

template <typename Type>
class ConstantNode : public Node
{
public:
    ConstantNode(int id, const char* name, const MC_Vector2f& pos)
        : Node(id, name, pos) {
        AddOutputPort(new OutputPort(this, GetPortType<Type>()));
    };

    void OnTraverse(GraphRunnerContext* aGraphRunnerContext) override {};
};

class ResultNode : public Node
{
public:
    ResultNode(int anID, const char* aLabel, const MC_Vector2f& aPosition)
        : Node(anID, aLabel, aPosition)
    {
        AddInputPort(new InputPort(this, FloatPort, nullptr));
    };

    void OnTraverse(GraphRunnerContext* aGraphRunnerContext) override {};
};

struct PerlinNoiseConstants
{
	f32 myFrequency;
	f32 myAmplitude;
	u32 mySeed;
};

class PerlinNoise2D : public Node
{
public:
	PerlinNoise2D(int anID, const char* aName, const MC_Vector2f& aPosition)
		: Node(anID, aName, aPosition)
	{
		AddInputPort(new InputPort(this, PortType::FloatPort, new Property<f32>(&myConstants.myFrequency, 0.0f, 20.0f)));
		AddInputPort(new InputPort(this, PortType::FloatPort, new Property<f32>(&myConstants.myAmplitude, -2.0f, 2.0f)));
		AddInputPort(new InputPort(this, PortType::UIntPort, new Property<u32>(&myConstants.mySeed, 0, U32_MAX)));

		//Add Properties

		AddOutputPort(new OutputPort(this, PortType::FloatPort));
	}

    void OnTraverse(GraphRunnerContext* aGraphRunnerContext) override {};
private:
	PerlinNoiseConstants myConstants;
};

static void locRegisterNodeTypes()
{
    RegisterNodeType<ConstantNode<f32>>("Constants/FloatConstantNode");
    RegisterNodeType<ConstantNode<s32>>("Constants/IntConstantNode");
    RegisterNodeType<ConstantNode<u32>>("Constants/UIntConstantNode");
    RegisterNodeType<PerlinNoise2D>("PerlinNoise2D");
    RegisterNodeType<ResultNode>("ResultNode", true);
}