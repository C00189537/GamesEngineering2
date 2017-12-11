#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <assert.h>     
#include "HealthComponent.h"

int main()
{
	HealthComponent *hc = new HealthComponent();

	bool healthUp = false;

	while (hc->getInt() > 0)
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
	}
	std::cout << "Dead" << std::endl;
	hc->setInt(50);
	std::cout << "Game Over" << std::endl;

	system("PAUSE");
}