#pragma once
#include "Component.h"
class ControlComponent : public Component
{
public:
	ControlComponent() {};
	~ControlComponent() {};

	SDL_Point getPoint() { return vel; }
	void setPoint(SDL_Point pos) { (this->vel = pos); }
	std::string getID() { return id; }

	void setInt() {}
	int getInt() { return 0; }


private:
	SDL_Point vel = {0, 0};
	std::string id = "Control";
};
