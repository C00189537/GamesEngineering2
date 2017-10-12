#include "Idle.h"
#include "Jumping.h"
#include "Climbing.h"

void Idle::jumping(Animation* a)
{
	std::cout << "Jumping" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Climbing" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
	a->setCurrent(new Climbing());
	delete this;
}
