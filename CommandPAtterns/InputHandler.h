#pragma once
#include "MacroCommand.h"
#include "ConcreteCommands.h"

class InputHandler
{
public:
	void handleInput();

private:


	JumpCommand j;
	FireCommand f;

	Command* buttonX_ = &j;
	Command* buttonY_ = &f;
	Command* buttonA_;
	Command* buttonB_;

	
};