#pragma once
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"
#include <vector>
class Entity
{

	

public:
	Entity() {}
	~Entity() {}
	Entity(std::string e) : id(e) {}
	void addComponent(Component *c) { components.push_back(c); }
	void removeComponent(Component *c) {};
	std::string getID() { return id; }
	std::vector<Component*> getComponents() { return components;	}

private:
	std::vector<Component*> components;
	std::string id;
};

