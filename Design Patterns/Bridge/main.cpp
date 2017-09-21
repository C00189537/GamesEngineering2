
//#include "HandleToCharacter.h"
#include "Player.h"
#include "DrawImpl.h"



int main()
{

	//HandleToCharacter handle;
	//handle->Print();

	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	std::cin.get();
	
	system("PAUSE");
}