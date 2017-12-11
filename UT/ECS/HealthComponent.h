#pragma once
#include "Component.h"
class HealthComponent : public Component
{
public:
	HealthComponent() : health(50) {}
	~HealthComponent() {};

	SDL_Point getPoint()
	{
		SDL_Point t = { 0, 0 };
			return t; 
	}
	void setPoint(SDL_Point val) {}
	std::string getID() { return id; }

	void setInt(int val) 
	{ 
		this->health += val;
		if (this->health > 100)
		{
			this->health = 100;
			std::cout << "Full Health" << std::endl;
		}
		else if (this->health < 0)
		{
			this->health = 0;
		}
	}
	int getInt() { return health; }

private:
	int health;
	std::string id = "Health";
};

