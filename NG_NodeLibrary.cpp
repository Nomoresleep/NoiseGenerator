#include "NG_NodeLibrary.h"

//TODO: Fix node ids
template<>
void ConstantNode<f32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String source;
    source.Format("float node_%d_0 = %f;\n", 0, 0.5f);
    aGraphRunnerContext->myGeneratedSource.Add(source);
}

template<>
void ConstantNode<u32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String source;
    source.Format("float node_%d_0 = %d;\n", 0, 0);
    aGraphRunnerContext->myGeneratedSource.Add(source);
}

template<>
void ConstantNode<s32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String source;
    source.Format("float node_%d_0 = %d;\n", 0, 0);
    aGraphRunnerContext->myGeneratedSource.Add(source);
}