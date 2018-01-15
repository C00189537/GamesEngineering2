#pragma once
#pragma once
#include "Component.h"
class PositionComponent : public Component
{
public:
	PositionComponent() {};
	~PositionComponent() {};

	SDL_Point getPoint() { return pos; }
	void setPoint(SDL_Point val) { (this->pos = val); }
	std::string getID() { return id; }

	void setInt(int val) {}
	int getInt() { return 0; }


private:
	SDL_Point pos = {10, 10};
	std::string id = "Position";
};