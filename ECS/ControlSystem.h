#pragma once
#pragma once
#include "Entity.h"

class ControlSystem

{

public:

	ControlSystem() {}
	~ControlSystem() {}

	void addEntity(Entity e) { entities.push_back(e); }
	void update() {

		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities[i].getComponents().size(); j++)
			{

			}
		}
	}

private:
	std::vector<Entity> entities;

};
