#pragma once
#include "Entity.h"


class AISystem

{

public:

	AISystem() {}
	~AISystem(){}

	void addEntity(Entity *e) { entities.push_back(e); }
	void update() {

		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i)->getComponents().size(); j++)
			{
				if (entities.at(i)->getComponents().at(j)->getID() == "Health")
				{
					std::cout << entities.at(i)->getID() << ": " << entities.at(i)->getComponents().at(j)->getInt() << std::endl;
				}
				if (entities.at(i)->getComponents().at(j)->getID() == "Position")
				{
					entities.at(i)->getComponents().at(j)->setPoint({ entities.at(i)->getComponents().at(j)->getPoint().x + 1,  entities.at(i)->getComponents().at(j)->getPoint().y });
					if (entities.at(i)->getComponents().at(j)->getPoint().x > 672)
					{
						entities.at(i)->getComponents().at(j)->setPoint({-32, entities.at(i)->getComponents().at(j)->getPoint().y });
					}
				}
			}
		}
	}

private:
	std::vector<Entity*> entities;

};
