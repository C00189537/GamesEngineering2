#pragma once
#include "Entity.h"


class RenderSystem
{
	


public:

	RenderSystem(SDL_Renderer* r) : rend(r){}
	~RenderSystem() {}


	void addEntity(Entity *e) { entities.push_back(e); }
	void update()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i)->getComponents().size(); j++)
			{
				if (entities.at(i)->getComponents().at(j)->getID() == "Position")
				{

					SDL_Rect rect;
					SDL_SetRenderDrawColor(rend, rand() % 255, rand() % 255, rand() % 255, 0);
					rect.x = entities.at(i)->getComponents().at(j)->getPoint().x;
					rect.y = entities.at(i)->getComponents().at(j)->getPoint().y;
					rect.h = 10;
					rect.w = 10;
					SDL_RenderFillRect(rend, &rect);
				}
			}
		}
	}

private:
	std::vector<Entity*> entities;
	SDL_Renderer * rend;

};
