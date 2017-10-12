#include <iostream>
#include <SDL.h>
#include ""



int main(int argc, char* argv[])
{
	
	std::cout << "Game initialised" << std::endl;

	std::cout << "Game Loop Starting....." << std::endl;
	std::string game = "Running";
	while (game == "Running")
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			default:
				break;
			}
		}
	}
	std::cout << "Calling Cleanup" << std::endl;


	return 0;
}