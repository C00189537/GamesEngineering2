#include "InputHandler.h"
#include <SDL.h>

void InputHandler::handleInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			//The client sends the request to the invoker.
			//The invoker carries out the request by performing execute.
			//The invoker sends the command to the reciever
			buttonX_->execute();
			break;
		case SDLK_2:
			buttonY_->execute();
			break;
		case SDLK_3:
			buttonX_->redo();
			break;
		default:
			break;
		}
	}
}
