#pragma once 

#include "NG_Node.h"
#include "NG_NodeModule.h"

template <typename Type>
const char* GetVariableTypeFromType();

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
        MC_String varName = MC_Strfmt<64>("%s%d", ConstOp::Name, myUID);
        MC_String param0 = myInputs[In0Idx]->myConnectedPort ? myInputs[In0Idx]->myConnectedPort->myData.myVariableName : MC_String(MC_Strfmt<64>("%f", myInputs[In0Idx]->myData.myValue.myFloat));
        MC_String param1 = myInputs[In1Idx]->myConnectedPort ? myInputs[In1Idx]->myConnectedPort->myData.myVariableName : MC_String(MC_Strfmt<64>("%f", myInputs[In1Idx]->myData.myValue.myFloat));
        MC_String source;
        source.Format("%s %s = %s %s %s;\n", GetVariableTypeFromType<Type>(), varName, param0, ConstOp::Operator, param1);
        aGraphRunnerContext->myGeneratedSource.Add(source);
        myOutputs[OutIdx]->myData.myVariableName = varName;
    }
};

class ResultNode : public NG_Node
{
private:
    enum InPortIdx
    {
        RedInIndex = 0,
        GreenInIndex = 1,
        BlueInIndex = 2,
    };
public:
    ResultNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        MC_String source;
        if (myInputs[RedInIndex]->myConnectedPort)
        {
            source.Format("result.r = %s;\n", myInputs[RedInIndex]->myConnectedPort->myData.myVariableName);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
        else
        {
            source.Format("result.r = %f;\n", myInputs[RedInIndex]->myData.myValue.myFloat);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }

        if (myInputs[GreenInIndex]->myConnectedPort)
        {
            source.Format("result.g = %s;\n", myInputs[GreenInIndex]->myConnectedPort->myData.myVariableName);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
        else
        {
            source.Format("result.g = %f;\n", myInputs[GreenInIndex]->myData.myValue.myFloat);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }

        if (myInputs[BlueInIndex]->myConnectedPort)
        {
            source.Format("result.b = %s;\n", myInputs[BlueInIndex]->myConnectedPort->myData.myVariableName);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
        else
        {
            source.Format("result.b = %f;\n", myInputs[BlueInIndex]->myData.myValue.myFloat);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
    };
};

class Split1To2Node : public NG_Node
{
private:
    enum InPortIdx
    {
        InIdx = 0,
    };

    enum OutPortIdx
    {
        Out0Idx = 0,
        Out1Idx = 1
    };
public:
    Split1To2Node(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::Vec2Port));

        AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort, true));
        AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort, true));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override
    {
        if (myInputs[InIdx]->myConnectedPort)
        {
            MC_String varName;
            varName.Format("%s.r;\n", myInputs[InIdx]->myConnectedPort->myData.myVariableName);
            myOutputs[Out0Idx]->myData.myVariableName = varName;
            varName.Format("%s.g;\n", myInputs[InIdx]->myConnectedPort->myData.myVariableName);
            myOutputs[Out1Idx]->myData.myVariableName = varName;
        }
    };
};

class Combine2To1Node : public NG_Node
{
private:
    enum InPortIdx
    {
        In0Idx = 0,
        In1Idx = 0,
    };

    enum OutPortIdx
    {
        Out0Idx = 0,
    };
public:
    Combine2To1Node(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));

        AddOutputPort(new NG_OutputPort(this, NG_Port::Vec2Port, true));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override
    {
        if (myInputs[In0Idx]->myConnectedPort && myInputs[In1Idx]->myConnectedPort)
        {
            MC_String varName = MC_Strfmt<64>("combine%d", myUID);
            MC_String source;
            source.Format("vec2 %s = vec2(%f, %f);\n", varName, myInputs[In0Idx]->myConnectedPort->myData.myValue.myFloat, myInputs[In1Idx]->myConnectedPort->myData.myValue.myFloat);
            myOutputs[Out0Idx]->myData.myVariableName = varName;
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