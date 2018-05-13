#include "Editor_Commands.h"
#include "Editor_NodeEditor.h"

Editor_NewNodeCommand::Editor_NewNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
	: myEditor(anEditor)
	, myNode(aNode)
	, myNodeUID(aNodeUID)
	, myNodeLabel(aNodeLabel)
	, myNodePosition(aPosition)
{
}

void Editor_NewNodeCommand::Execute()
{
	myEditor->CreateNode(myNode, myNodeUID, myNodeLabel, myNodePosition);
}

void Editor_NewNodeCommand::Undo()
{
	myEditor->RemoveNode(myNode);
}

Editor_RemoveNodeCommand::Editor_RemoveNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
	: myEditor(anEditor)
	, myNode(aNode)
	, myNodeUID(aNodeUID)
	, myNodeLabel(aNodeLabel)
	, myNodePosition(aPosition)
{
}

void Editor_RemoveNodeCommand::Execute()
{
	myEditor->RemoveNode(myNode);
}

void Editor_RemoveNodeCommand::Undo()
{
	myEditor->CreateNode(myNode, myNodeUID, myNodeLabel, myNodePosition);
}