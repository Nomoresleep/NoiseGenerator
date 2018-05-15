#include "NG_NodeLibrary.h"

//TODO: Fix node ids
template<>
void ConstantNode<f32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
	MC_String source;
	source.Format("float node_%d_0 = %f;\n", myUID, 0.5f);
	aGraphRunnerContext->myGeneratedSource.Add(source);
}

template<>
void ConstantNode<u32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
	MC_String source;
	source.Format("float node_%d_0 = %d;\n", myUID, 0);
	aGraphRunnerContext->myGeneratedSource.Add(source);
}

template<>
void ConstantNode<s32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
	MC_String source;
	source.Format("float node_%d_0 = %d;\n", myUID, 0);
	aGraphRunnerContext->myGeneratedSource.Add(source);
}

void NodeLibrary::RegisterNodeTypes()
{
	NG_RegisterNodeType<ConstantNode<f32>>("Constants/FloatConstantNode");
	NG_RegisterNodeType<ConstantNode<s32>>("Constants/IntConstantNode");
	NG_RegisterNodeType<ConstantNode<u32>>("Constants/UIntConstantNode");
	NG_RegisterNodeType<PerlinNoise2D>("PerlinNoise2D");
	NG_RegisterNodeType<ResultNode>("ResultNode");
}

void NodeLibrary::UnregisterNodeTypes()
{
	NG_UnregisterNodeType("Constants/FloatConstantNode");
	NG_UnregisterNodeType("Constants/IntConstantNode");
	NG_UnregisterNodeType("Constants/UIntConstantNode");
	NG_UnregisterNodeType("PerlinNoise2D");
	NG_UnregisterNodeType("ResultNode");
}