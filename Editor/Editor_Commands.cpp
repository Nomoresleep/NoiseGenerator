#include "Editor_Commands.h"
#include "Editor_NodeEditor.h"

Editor_NodeCreationCommand::Editor_NodeCreationCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
	: myEditor(anEditor)
	, myNode(aNode)
	, myNodeUID(aNodeUID)
	, myNodeLabel(aNodeLabel)
	, myNodePosition(aPosition)
{
}

void Editor_NodeCreationCommand::AddNode()
{
	myEditor->CreateNode(myNode, myNodeUID, myNodeLabel, myNodePosition);
}

void Editor_NodeCreationCommand::RemoveNode()
{
	myEditor->RemoveNode(myNode);
}

Editor_CreateNodeCommand::Editor_CreateNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
    : Editor_NodeCreationCommand(anEditor, aNode, aNodeUID, aNodeLabel, aPosition)
{
}

void Editor_CreateNodeCommand::Execute()
{
    Editor_NodeCreationCommand::AddNode();
}

void Editor_CreateNodeCommand::Undo()
{
    Editor_NodeCreationCommand::RemoveNode();
}

Editor_RemoveNodeCommand::Editor_RemoveNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
    : Editor_NodeCreationCommand(anEditor, aNode, aNodeUID, aNodeLabel, aPosition)
{
}

void Editor_RemoveNodeCommand::Execute()
{
    Editor_NodeCreationCommand::AddNode();
}

void Editor_RemoveNodeCommand::Undo()
{
    Editor_NodeCreationCommand::RemoveNode();
}