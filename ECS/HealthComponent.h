#pragma once
#include "Component.h"
class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {}
	~HealthComponent() {};

	SDL_Point getPoint()
	{
		SDL_Point t = { 0, 0 };
			return t; 
	}
	void setPoint(SDL_Point val) {}
	std::string getID() { return id; }

	void setInt(int val) { this->health = val; }
	int getInt() { return health; }

private:
	int health;
	std::string id = "Health";
};

