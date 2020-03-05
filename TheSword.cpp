//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19

#include "characterClass.h" //needed to make a new Player1
#include "playerHelp.h"		//needed to call the playerHelp function
#include "openingChamber.h" //needed to call openingChamber
#include "RoomRow1.h" //needed to call the row1Function
#include "RoomRow2.h" //needed to call row2Function
#include "RoomRow3.h" //needed to call row3Function
#include "RoomRow4.h" //needed to call row4Function
#include "bossRoom.h" //needed to call bossFunction
#include "swordRoom.h" //needed to call swordFunction

using namespace std;


int main()
{
	
	//Object creation
	Player1 character;
	
	playerHelp();
	openingChamber(character);
	row1Function(character); //Sword and gem 1 is in this room
	row2Function(character); //Shield and gem 2 is in this room
	row3Function(character); //gem 3, potion, miniboss
	row4Function(character); //gem 4, potions, old man smite
	bossFunction(character); //drops gems in statue and fights boss
	swordFunction(character); //grabs sword to finish game
	cout << "You beat the game!" << endl;
	
	
	
return 0;
}
