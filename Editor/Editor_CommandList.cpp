#include "Editor_CommandList.h"
#include "Editor_Commands.h"

Editor_CommandList::Editor_CommandList()
	: myCommandIndexPointer(0)
{
}

void Editor_CommandList::ExecuteCommand(Editor_Command* aCommand)
{
	if (myCommandIndexPointer == myCommands.Count())
	{
		myCommands.Add(aCommand);
		aCommand->Execute();
		myCommandIndexPointer = myCommands.Count();
	}
	else
	{
		assert(false);
	}
}

void Editor_CommandList::Undo()
{
	if (myCommandIndexPointer > 0)
	{
		myCommandIndexPointer--;
		myCommands[myCommandIndexPointer]->Undo();
	}
}

void Editor_CommandList::Redo()
{
	if (myCommandIndexPointer < myCommands.Count())
	{
		myCommands[myCommandIndexPointer]->Execute();
		myCommandIndexPointer++;
	}
}
