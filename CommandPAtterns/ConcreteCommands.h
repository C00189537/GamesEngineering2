#pragma once
#include "Command.h"

class JumpCommand : public Command
{
public:
	virtual void execute() { std::cout << "Jump" << std::endl; }
	virtual void undo() {}
	virtual void redo() {}

};

class FireCommand : public Command
{
public:
	virtual void execute() { std::cout << "Fire Gun" << std::endl; }
	virtual void undo() {}
	virtual void redo() {}

};