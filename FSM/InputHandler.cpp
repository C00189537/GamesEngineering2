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
			std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
			break;
		case SDLK_2:
			fsm.climbing();
			std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
			break;
		default:
			fsm.idle();
			//std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
			break;
		}
	}
}
