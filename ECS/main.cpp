#include <iostream>
#include "InputHandler.h"
#include "SDL.h"
#include "RenderSystem.h"
#include "AISystem.h"

void setupEntity(Entity e, int x, int y, int health);

int main(int argc, char* argv[])
{

	std::cout << "Game initialised" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("ECS",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	Entity player("Player");
	Entity cat("Cat");
	Entity dog("Dog");
	Entity alien("Alien");

	//position component
	player.addComponent(new PositionComponent());
	cat.addComponent(new PositionComponent());
	dog.addComponent(new PositionComponent());
	alien.addComponent(new PositionComponent());

	//health component
	player.addComponent(new HealthComponent());
	cat.addComponent(new HealthComponent());
	dog.addComponent(new HealthComponent());
	alien.addComponent(new HealthComponent());

	setupEntity(player, 100, 100, 100);
	setupEntity(cat, 200, 200, 10);
	setupEntity(dog, 300, 300, 20);
	setupEntity(alien, 400, 400, 200);

	/*cat.getComponents().at(0)->setPoint({ 20, 20 });
	dog.getComponents().at(0)->setPoint({ 30, 30 });
	alien.getComponents().at(0)->setPoint({ 40, 40 });*/

	//

	RenderSystem rs(renderer);
	rs.addEntity(&player);
	rs.addEntity(&cat);
	rs.addEntity(&dog);
	rs.addEntity(&alien);

	AISystem as;
	as.addEntity(&cat);
	as.addEntity(&dog);
	as.addEntity(&alien);

	

	std::cout << "Game Loop Starting....." << std::endl;
	std::string game = "Running";
	while (game == "Running")
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		
		rs.update();
		as.update();
		
		SDL_RenderPresent(renderer);
	}



	return 0;
}

void setupEntity(Entity e, int x, int y, int health)
{
	for (int i = 0; i < e.getComponents().size(); i++)
	{
		if (e.getComponents().at(i)->getID() == "Position")
		{
			e.getComponents().at(i)->setPoint({ x, y });
		}
		if (e.getComponents().at(i)->getID() == "Health")
		{
			e.getComponents().at(i)->setInt(health);
		}
	}
}