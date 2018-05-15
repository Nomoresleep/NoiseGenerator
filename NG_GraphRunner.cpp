#include "NG_GraphRunner.h"

namespace
{
	struct NodeComparator
	{
		static bool LessThan(NG_Node* a, NG_Node* b) { return a->ConnectedInputCount() < b->ConnectedInputCount(); }
		static bool Equals(NG_Node* a, NG_Node* b) { return a->ConnectedInputCount() == b->ConnectedInputCount(); }
	};
}

NG_GraphRunner::NG_GraphRunner(NG_NodeGraph* aNodegraph)
	: myNodegraph(aNodegraph)
{}


void NG_GraphRunner::Run()
{
	MC_BinaryHeap<NG_Node*, ::NodeComparator> pqueue(myNodegraph->GetNodes().Count());
	NG_GraphRunnerContext runnerContext;

	static const char* locComputeShaderString1 =
		"layout(local_size_x = 8, local_size_y = 8) in;\n"
		"layout(rgba32f, binding = 0) uniform image2D img_output;\n"
		"void main(){\n"
		"ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);\n"
		"vec2 UV = (pixel_coords.xy / 1024.0) * 16.0;\n"
		"float result = 0.0;\n";
	static const char* locComputeShaderString2 =
		//"float perlin = PerlinNoise2D(x,y);\n"
		"vec4 pixel_value = vec4(result, result, result, 1.0);\n"
		"imageStore(img_output, pixel_coords, pixel_value);\n"
		"}";

	runnerContext.myGeneratedSource.Add(locComputeShaderString1);

	for (s32 nodeIdx = 0; nodeIdx < myNodegraph->GetNodes().Count(); ++nodeIdx)
	{
		NG_Node* node = myNodegraph->GetNodes()[nodeIdx];
		if (node->ConnectedInputCount() == 0)
			pqueue.Push(node);
	}

	while (!pqueue.IsEmpty())
	{
		const NG_Node* node = pqueue.Pop();
		node->OnTraverse(&runnerContext);
		for (s32 outPortIdx = 0; outPortIdx < node->myOutputs.Count(); ++outPortIdx)
		{
			const NG_OutputPort* outPort = node->myOutputs[outPortIdx];
			for (s32 inPortIdx = 0; inPortIdx < outPort->myConnectedInputs.Count(); ++inPortIdx)
			{
				const NG_InputPort* inPort = outPort->myConnectedInputs[inPortIdx];
				pqueue.PushUnique(inPort->myNode);
			}
		}
	}

	runnerContext.myGeneratedSource.Add(locComputeShaderString2);

	mySource.Clear();
	for (s32 i = 0; i < runnerContext.myGeneratedSource.Count(); ++i)
		mySource += runnerContext.myGeneratedSource[i];
}