#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <iostream>
class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();
};
#endif // !ANIMATION_H_