
#ifndef IDLE_H_
#define IDLE_H_

#include "State.h"
#include <thread>
#include <chrono>

class Idle : public State
{
public:
	Idle() { std::cout << "Idle" << std::endl; };
	~Idle() {  };
	void jumping(Animation* a);
	void climbing(Animation* a);
};
#endif // !
