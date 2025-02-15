#pragma once
#include "Character.h"
#include "DrawAPI.h"


class Player : public Character
{
public:

	Player(DrawAPI* api) { this->api = api; }
	void Draw() { api->Draw(); }

private:
	DrawAPI* api;
};