#include "NG_GraphRunner.h"
#include "MCC_BinaryHeap.h"

namespace
{
	struct NodeComparator
	{
		static bool LessThan(const NG_Node* a, const NG_Node* b) { return a->ConnectedInputCount() < b->ConnectedInputCount(); }
		static bool Equals(const NG_Node* a, const NG_Node* b) { return a->ConnectedInputCount() == b->ConnectedInputCount(); }
	};
}

NG_GraphRunner::NG_GraphRunner(NG_NodeGraph* aNodegraph)
	: myNodegraph(aNodegraph)
{}


void NG_GraphRunner::Run()
{
	MC_BinaryHeap<const NG_Node*, ::NodeComparator> pqueue(myNodegraph->GetNodes().Count());
	NG_GraphRunnerContext runnerContext;

	static const char* locComputeShaderString1 =
		"layout(local_size_x = 8, local_size_y = 8) in;\n"
		"layout(rgba32f, binding = 0) uniform image2D img_output;\n"
		"void main(){\n"
		"ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);\n"
		"vec2 UV = (pixel_coords.xy / 1024.0) * 16.0;\n"
		"vec3 result = vec3(0.0, 0.0, 0.0);\n";
	static const char* locComputeShaderString2 =
		"vec4 pixel_value = vec4(result, 1.0);\n"
		"imageStore(img_output, pixel_coords, pixel_value);\n"
		"}";

	runnerContext.myGeneratedSource.Add(locComputeShaderString1);

	MC_HashMap<const NG_Node*, s32> activeConnectionCount;
	for (s32 nodeIdx = 0; nodeIdx < myNodegraph->GetNodes().Count(); ++nodeIdx)
	{
		const NG_Node* node = myNodegraph->GetNodes()[nodeIdx];
		s32 connectionCount = node->ConnectedInputCount();
		if (connectionCount == 0)
			pqueue.Push(node);

		activeConnectionCount[node] = connectionCount;
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
				if (--activeConnectionCount[inPort->myNode] <= 0)
				{
					pqueue.PushUnique(inPort->myNode);
				}
			}
		}
	}

	runnerContext.myGeneratedSource.Add(locComputeShaderString2);

	mySource.Clear();
	for (s32 i = 0; i < runnerContext.myGeneratedSource.Count(); ++i)
		mySource += runnerContext.myGeneratedSource[i];
}