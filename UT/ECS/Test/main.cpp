#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <assert.h>     
#include "HealthComponent.h"

int main()
{
	HealthComponent *hc = new HealthComponent();
	bool alive = true;
	bool healthUp = false;

	while (alive)
	{
		//In lava
		if (!healthUp)
		{
			hc->setInt(-5);
			assert(hc->getInt() >= 0);
			std::cout << hc->getInt() << std::endl;
		}
		//In healing pool
		else
		{
			hc->setInt(5);
			assert(hc->getInt() <= 100);
			std::cout << hc->getInt() << std::endl;
		}
		if (hc->getInt() <= 0)
		{
			assert(alive == true);
			alive = false;
		}
	}
	std::cout << "Dead" << std::endl;
	std::cout << "Game Over" << std::endl;

	system("PAUSE");
}