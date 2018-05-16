#pragma once 

#include "NG_Node.h"
#include "NG_NodeModule.h"

template <typename Type>
class ConstantNode : public NG_Node
{
private:
    enum OutPortIdx
    {
        OutIdx = 0
    };
public:
    ConstantNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>(), false));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override;

	Type myConstant;
};

template <typename Type, typename ConstBuildIn>
class BuildInConstantNode : public NG_Node
{
private:
    enum OutPortIdx
    {
        OutIdx = 0
    };
public:
    BuildInConstantNode(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>(), true));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        (void)aGraphRunnerContext;
        myOutputs[OutIdx]->myData.myVariableName = ConstBuildIn::BuildIn;
    }
};

template <typename Type, typename ConstOp>
class OperationNodeTwoWay : public NG_Node
{
private:
    enum InPortIdx
    {
        In0Idx = 0,
        In1Idx = 1,
    };
    enum OutPortIdx
    {
        OutIdx = 0
    };
public:
    OperationNodeTwoWay(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, GetPortType<Type>()));
        AddInputPort(new NG_InputPort(this, GetPortType<Type>()));

        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>(), true));
    }

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override
    {
        if (myInputs[In0Idx]->myConnectedPort && myInputs[In1Idx]->myConnectedPort)
        {
            MC_String varName = MC_Strfmt<64>("%s%d", ConstOp::Name, myUID);
            MC_String source;
            source.Format("vec2 %s = %s %s %s;\n", varName, myInputs[In0Idx]->myConnectedPort->myData.myVariableName, ConstOp::Operator, myInputs[In1Idx]->myConnectedPort->myData.myVariableName);
            aGraphRunnerContext->myGeneratedSource.Add(source);
            myOutputs[OutIdx]->myData.myVariableName = varName;
        }
    }
};

class ResultNode : public NG_Node
{
private:
    enum InPortIdx
    {
        ResultInIndex = 0
    };
public:
    ResultNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        if (myInputs[ResultInIndex]->myConnectedPort)
        {
            MC_String source;
            source.Format("result = %s;\n", myInputs[ResultInIndex]->myConnectedPort->myData.myVariableName);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
    };
};

class PerlinNoise2D : public NG_Node
{
private:
    enum InPortIdx
    {
        UVInIdx = 0
    };
    enum OutPortIdx
    {
        PerlinOutIdx = 0
    };
public:
	PerlinNoise2D(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
		AddInputPort(new NG_InputPort(this, NG_Port::Vec2Port));

		AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort, true));
	}

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        MC_String varName = MC_Strfmt<32>("perlinNoise2D%d", myUID);
        MC_String argName;
        if (myInputs[UVInIdx]->myConnectedPort)
        {
            argName = myInputs[UVInIdx]->myConnectedPort->myData.myVariableName;
        }
		MC_String source;
		source.Format("float %s = PerlinNoise2D(%s);\n", varName, argName);
		aGraphRunnerContext->myGeneratedSource.Add(source);
        myOutputs[PerlinOutIdx]->myData.myVariableName = varName;
    };
};

namespace NodeLibrary
{
	void RegisterNodeTypes();
	void UnregisterNodeTypes();
}