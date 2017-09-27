#include <iostream>
#include "InputHandler.h"


int main(int argc, char* argv[])
{
	
	std::cout << "Game initialised" << std::endl;

	std::cout << "Game Loop Starting....." << std::endl;
	std::string game = "Running";
	InputHandler inputHandle;
	while (game == "Running")
	{
		inputHandle.handleInput();
	}
	std::cout << "Calling Cleanup" << std::endl;


	return 0;
}