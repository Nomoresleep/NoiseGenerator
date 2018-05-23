#include "Editor_Commands.h"
#include "Editor_NodeEditor.h"
#include "Editor_NodeTools.h"

Editor_MakroCommand::Editor_MakroCommand(const char* aMakroName)
    : myMakroName(aMakroName)
{
}

Editor_MakroCommand::~Editor_MakroCommand()
{
    myCommands.DeleteAll();
}

void Editor_MakroCommand::AddCommand(Editor_Command* aCommand)
{
    myCommands.Add(aCommand);
}

void Editor_MakroCommand::Execute()
{
    for (s32 commandIdx = 0; commandIdx < myCommands.Count(); ++commandIdx)
        myCommands[commandIdx]->Execute();
}

void Editor_MakroCommand::Undo()
{
    for (s32 commandIdx = myCommands.Count() - 1; commandIdx >= 0; --commandIdx)
        myCommands[commandIdx]->Undo();
}

Editor_NodeCreationCommand::Editor_NodeCreationCommand(const char* aMakroName, Editor_NodeEditor* anEditor, NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition)
	: Editor_MakroCommand(aMakroName)
    , myEditor(anEditor)
	, myNode(aNode)
	, myNodeLabel(aNodeLabel)
	, myNodePosition(aPosition)
{
}

void Editor_NodeCreationCommand::AddNode()
{
	myEditor->CreateNode(myNode, myNodeLabel, myNodePosition);
}

void Editor_NodeCreationCommand::RemoveNode()
{
	myEditor->RemoveNode(myNode);
}

Editor_CreateNodeCommand::Editor_CreateNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition)
    : Editor_NodeCreationCommand("Create Node", anEditor, aNode, aNodeLabel, aPosition)
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

Editor_RemoveNodeCommand::Editor_RemoveNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition)
    : Editor_NodeCreationCommand("Remove Node", anEditor, aNode, aNodeLabel, aPosition)
{
    for (s32 inputIdx = 0; inputIdx < aNode->myInputs.Count(); ++inputIdx)
    {
        NG_InputPort* input = aNode->myInputs[inputIdx];
        AddCommand(new Editor_NodeDisconnectCommand(input->myConnectedPort, input));
    }

    for (s32 outputIdx = 0; outputIdx < aNode->myOutputs.Count(); ++outputIdx)
    {
        NG_OutputPort* output = aNode->myOutputs[outputIdx];
        for (s32 inputIdx = 0; inputIdx < output->myConnectedInputs.Count(); ++inputIdx)
        {
            AddCommand(new Editor_NodeDisconnectCommand(output, output->myConnectedInputs[inputIdx]));
        }
    }
}

void Editor_RemoveNodeCommand::Execute()
{
    Editor_MakroCommand::Execute();
    Editor_NodeCreationCommand::RemoveNode();
}

void Editor_RemoveNodeCommand::Undo()
{
    Editor_NodeCreationCommand::AddNode();
    Editor_MakroCommand::Undo();
}

Editor_NodeConnectCommand::Editor_NodeConnectCommand(NG_OutputPort* anOutputPort, NG_InputPort* anInputPort)
    : myOutputPort(anOutputPort)
    , myInputPort(anInputPort)
{
}

void Editor_NodeConnectCommand::Execute()
{
    myInputPort->Connect(myOutputPort);
}

void Editor_NodeConnectCommand::Undo()
{
    myInputPort->Connect(nullptr);
}

Editor_NodeDisconnectCommand::Editor_NodeDisconnectCommand(NG_OutputPort* anOutputPort, NG_InputPort* anInputPort)
    : myOutputPort(anOutputPort)
    , myInputPort(anInputPort)
{
}

void Editor_NodeDisconnectCommand::Execute()
{
    myInputPort->Connect(nullptr);
}

void Editor_NodeDisconnectCommand::Undo()
{
    myInputPort->Connect(myOutputPort);
}

Editor_NodeMoveCommand::Editor_NodeMoveCommand(Editor_NodeProperties* someNodeProps, const MC_Vector2f& aNewPosition, const MC_Vector2f& anOldPosition)
    : myNodeProps(someNodeProps)
    , myNewPosition(aNewPosition)
    , myOldPosition(anOldPosition)
{

}

void Editor_NodeMoveCommand::Execute()
{
    myNodeProps->myPosition = myNewPosition;
}

void Editor_NodeMoveCommand::Undo()
{
    myNodeProps->myPosition = myOldPosition;
}

Editor_SelectionChangeCommand::Editor_SelectionChangeCommand(Editor_NodeEditor* aNodeEditor, const Editor_NodeGraphSelection& aNewSelection, const Editor_NodeGraphSelection& anOldSelection)
	: myNodeEditor(aNodeEditor)
	, myNewSelection(aNewSelection)
	, myOldSelection(anOldSelection)
{
}

void Editor_SelectionChangeCommand::Execute()
{
	myNodeEditor->SetSelection(myNewSelection);
}

void Editor_SelectionChangeCommand::Undo()
{
	myNodeEditor->SetSelection(myOldSelection);
}