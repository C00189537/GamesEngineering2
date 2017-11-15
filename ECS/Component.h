#pragma once
#include <iostream>
#include <string>
#include "SDL.h"
#include "BasicTypes.h"
class Component
{
public:
	Component() {}
	~Component() {}
	virtual std::string getID() = 0;
	virtual SDL_Point getPoint() = 0;
	virtual int getInt() = 0;
	virtual void setPoint(SDL_Point val) = 0;
	virtual void setInt(int val) = 0;
	std::string id = "Base";

};

