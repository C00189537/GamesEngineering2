#pragma once
#pragma once
#include "Entity.h"

class ControlSystem

{

public:

	ControlSystem() {}
	~ControlSystem() {}

	void addEntity(Entity *e) { entities.push_back(e); }
	void update() {

		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities[i]->getComponents().size(); j++)
			{
				if (entities.at(i)->getComponents().at(j)->getID() == "Position")
				{
					//Keyboard control
					SDL_Event event;
					while (SDL_PollEvent(&event))
					{
						switch (event.key.keysym.sym)
						{
						case SDLK_a:
							entities.at(i)->getComponents().at(j)->setPoint({ entities.at(i)->getComponents().at(j)->getPoint().x - 5,  entities.at(i)->getComponents().at(j)->getPoint().y });
							break;
						case SDLK_d:
							entities.at(i)->getComponents().at(j)->setPoint({ entities.at(i)->getComponents().at(j)->getPoint().x + 5,  entities.at(i)->getComponents().at(j)->getPoint().y });
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}

private:
	std::vector<Entity*> entities;

};
