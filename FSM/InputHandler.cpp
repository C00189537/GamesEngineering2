#include "InputHandler.h"
#include <SDL.h>
#include <thread>
#include <chrono>
#include <iostream>

void InputHandler::handleInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			fsm.jumping();	
			break;
		case SDLK_2:
			fsm.climbing();
			break;
		default:
			fsm.idle();
			break;
		}
	}
}
