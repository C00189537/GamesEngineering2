#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <assert.h>     
#include "HealthComponent.h"

int main()
{
	HealthComponent *hc = new HealthComponent();
	bool alive = true;
	bool gameOver = false;
	bool healthUp = false;

	while (alive)
	{
		//Test if in lava
		if (!healthUp)
		{
			hc->setInt(-5);
			assert(hc->getInt() >= 0);
			std::cout << hc->getInt() << std::endl;
		}
		//Test if in healing pool
		else
		{
			hc->setInt(5);
			assert(hc->getInt() <= 100);
			std::cout << hc->getInt() << std::endl;
		}
		//Test if alive
		if (hc->getInt() <= 0)
		{
			assert(alive == true);
			alive = false;
			std::cout << "Dead" << std::endl;
			gameOver = true;
		}
	}
	
	//Test For Game Over
	assert(gameOver);
	std::cout << "Game Over" << std::endl;

	system("PAUSE");
}