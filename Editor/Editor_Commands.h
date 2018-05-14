#pragma once

class NG_Node;
struct NG_OutputPort;
struct NG_InputPort;
struct Editor_NodeProperties;
class Editor_NodeEditor;

#include "MC_Vector.h"
#include "MC_GrowingArray.h"

class Editor_Command
{
public:
    virtual const char* GetCommandName() const = 0;
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

class Editor_MakroCommand : public Editor_Command
{
public:
    Editor_MakroCommand(const char* aMakroName);
    ~Editor_MakroCommand();
    void AddCommand(Editor_Command* aCommand);

    const char* GetCommandName() const override { return myMakroName; }
    void Execute() override;
    void Undo() override;
protected:
    MC_GrowingArray<Editor_Command*> myCommands;
    const char* myMakroName;
};

class Editor_NodeCreationCommand : public Editor_MakroCommand
{
public:
    Editor_NodeCreationCommand(const char* aMakroName, Editor_NodeEditor* anEditor, NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition);

protected:
    void AddNode();
    void RemoveNode();

	Editor_NodeEditor* myEditor;
	NG_Node* myNode;
	const char* myNodeLabel;
	MC_Vector2f myNodePosition;
};

class Editor_CreateNodeCommand : public Editor_NodeCreationCommand
{
public:
    Editor_CreateNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition);

    void Execute() override;
    void Undo() override;
};

class Editor_RemoveNodeCommand : public Editor_NodeCreationCommand
{
public:
    Editor_RemoveNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition);

    void Execute() override;
    void Undo() override;
};

class Editor_NodeConnectCommand : public Editor_Command
{
public:
    Editor_NodeConnectCommand(NG_OutputPort* anOutputPort, NG_InputPort* anOldInputPort);

    const char* GetCommandName() const override { return "Connect Nodes"; }
    void Execute() override;
    void Undo() override;

private:
    NG_OutputPort* myOutputPort;
    NG_InputPort* myInputPort;
};

class Editor_NodeDisconnectCommand : public Editor_Command
{
public:
    Editor_NodeDisconnectCommand(NG_OutputPort* anOutputPort, NG_InputPort* anOldInputPort);

    const char* GetCommandName() const override { return "Disconnect Nodes"; }
    void Execute() override;
    void Undo() override;

private:
    NG_OutputPort* myOutputPort;
    NG_InputPort* myInputPort;
};

class Editor_NodeMoveCommand : public Editor_Command
{
public:
    Editor_NodeMoveCommand(Editor_NodeProperties* someNodeProps, const MC_Vector2f& aNewPosition, const MC_Vector2f& anOldPosition);

    const char* GetCommandName() const override { return "Move Node"; }
    void Execute() override;
    void Undo() override;
private:
    Editor_NodeProperties* myNodeProps;
    MC_Vector2f myNewPosition;
    MC_Vector2f myOldPosition;
};