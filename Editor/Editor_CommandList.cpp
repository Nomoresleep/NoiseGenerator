#include "Editor_CommandList.h"
#include "Editor_Commands.h"

Editor_CommandList::Editor_CommandList()
	: myCommandIndexPointer(0)
{
}

void Editor_CommandList::ExecuteCommand(Editor_Command* aCommand)
{
    if (myCommandIndexPointer != myCommands.Count())
    {
        //TODO: Nodes that have been removed by a command can be deleted when the command itself is removed by command stack discard
        for (s32 commandIdx = myCommandIndexPointer; commandIdx < myCommands.Count(); ++commandIdx)
        {
            delete myCommands[commandIdx];
        }
        myCommands.RemoveNAtEnd(myCommands.Count() - myCommandIndexPointer);
    }

    myCommands.Add(aCommand);
    aCommand->Execute();
    myCommandIndexPointer = myCommands.Count();
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
