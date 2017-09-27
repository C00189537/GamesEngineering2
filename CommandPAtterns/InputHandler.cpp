#include "InputHandler.h"
#include <SDL.h>

void InputHandler::handleInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDLK_1:
		{
			buttonX_->execute();
		}
		break;
		case SDLK_2:
		{
			buttonX_->undo();
		}
		break;
		case SDLK_3:
		{
			buttonX_->redo();
		}
		break;
		default:
			break;
		}
	}
}
