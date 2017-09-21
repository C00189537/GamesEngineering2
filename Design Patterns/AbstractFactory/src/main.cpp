#include <iostream>
#include <SDL.h>
//#include <SDL_image.h>

int main(int argc, char* argv[])
{
	std::cout <<"Game Object Created" << std::endl;
	//Create game object
	//Game* game = new Game;
	//game->Initialize("DGPP Skelatol", 0, 0, 1366, 768, SDL_WINDOW_FULLSCREEN | SDL_WINDONW_INPUT_FOCUS);
	std::cout << "Game initialised" << std::endl;

	std::cout << "Game Loop Starting....." << std::endl;
	//while (game->isRunning())
	//{
		//game->HandleEvents();
		//game->Update();
		//game->Render();
	//}
	std::cout << "Calling Cleanup" << std::endl;
	//game->CleanUp();

	return 0;
}