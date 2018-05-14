#pragma once

class NG_Node;
class Editor_NodeEditor;

#include "MC_Vector.h"

class Editor_Command
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

class Editor_NodeCreationCommand : public Editor_Command
{
public:
    Editor_NodeCreationCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition);

protected:
    void AddNode();
    void RemoveNode();

	Editor_NodeEditor* myEditor;
	NG_Node* myNode;
	u32 myNodeUID;
	const char* myNodeLabel;
	MC_Vector2f myNodePosition;
};

class Editor_CreateNodeCommand : public Editor_NodeCreationCommand
{
public:
    Editor_CreateNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition);

    void Execute() override;
    void Undo() override;
};

class Editor_RemoveNodeCommand : public Editor_NodeCreationCommand
{
public:
    Editor_RemoveNodeCommand(Editor_NodeEditor* anEditor, NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition);

    void Execute() override;
    void Undo() override;
};