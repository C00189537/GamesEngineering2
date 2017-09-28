#include <iostream>
#include "InputHandler.h"
#include "SDL.h"


int main(int argc, char* argv[])
{
	
	std::cout << "Game initialised" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("SDL Command Patterns",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = SDL_LoadBMP("spaceship.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,image);
	SDL_FreeSurface(image);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


	std::cout << "Game Loop Starting....." << std::endl;
	std::string game = "Running";
	InputHandler inputHandle;
	while (game == "Running")
	{
		inputHandle.handleInput();


		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	std::cout << "Calling Cleanup" << std::endl;


	return 0;
}