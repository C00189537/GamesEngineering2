#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <assert.h>     
#include "HealthComponent.h"

int main()
{
	HealthComponent *hc = new HealthComponent();

	hc->setInt(100);
	
	assert(hc->getInt() <= 200);
	std::cout << hc->getInt() << std::endl;

	hc->setInt(250);

	assert(hc->getInt() <= 200);
	std::cout << hc->getInt() << std::endl;

	system("PAUSE");
}