#pragma once

#include "MC_ScopedPtr.h"
#include "MC_GrowingArray.h"
#include "Editor_Commands.h"

class Editor_CommandList
{
public:
	Editor_CommandList();

	void ExecuteCommand(Editor_Command* aCommand);
	void Undo();
	void Redo();

    s32 Count() const { return myCommands.Count(); }

    const Editor_Command* const operator[](s32 anIndex) const
    {
        return myCommands[anIndex];
    }
private:
	MC_GrowingArray<Editor_Command*> myCommands;
	s32 myCommandIndexPointer;
};