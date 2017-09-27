#pragma once
#include "Command.h"
#include <list>

class MacroCommand : public Command {

public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command* c);
	virtual void remove(Command* c);
	virtual void execute();
	virtual void undo();
	virtual void redo();

private:

	std::list<Command*>* commands;
	std::list<Command*>* undoneCommands;

};