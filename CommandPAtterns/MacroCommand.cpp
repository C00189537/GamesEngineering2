#include "MacroCommand.h"

//Executes the commands in the command list
void MacroCommand::execute()
{
	std::list<Command*>::iterator i;

	for (i = commands->begin(); i != commands->end(); i++)
	{
		Command *c = *i;
		c->execute();
	}
}
//Adds the last command to a undo list and erases it from the command list
void MacroCommand::undo()
{
	undoneCommands->push_back(*commands->end());
	commands->erase(commands->end());

}
//Removes the last command from the undo list and adds it to the command list
void MacroCommand::redo()
{
	commands->push_back(*undoneCommands->end());
	undoneCommands->erase(undoneCommands->end());
}
//Adds a command to the command list
void MacroCommand::add(Command* c)
{
	commands->push_back(c);
}
//Removes a command from the command list
void MacroCommand::remove(Command* c)
{
	commands->remove(c);
}