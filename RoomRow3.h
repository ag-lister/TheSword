//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19
//4 rooms, holds gem 3, a potion, and the mini boss
 
#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <string>

//Building strings
#define LINEOUT(str) cout << #str << endl

#pragma once

bool row3Function(Player1& character)
{
	string answer = "";
	int count = 0; //Incremented only once, but still useful
	bool room1entered = false;
	bool room2entered = false;
	bool roomComplete = false;
	bool chestSearched = false;
	bool bookshelfSearched = false;
	bool gemFound = false;
	bool knightDead = false;
	
	//Knight fight
	int knightHealth = 20;
	int combatNum = 0;
	unsigned seed = time(0);
	srand(seed);
	int randomNum = 0; //used later
	
	system("cls");
	cout << "You come to a another room with a door on the left and a door on the right." << endl;
	
	while(!gemFound){
	
	int ansNum = 0;
	if(count == 0){
	count++;
	LINEOUT(What will you do?);
	getline(cin, answer);
	} else {
	system("cls");
	ansNum = 0;
	LINEOUT(Youre back in the middle room with the two doors.);
	cout << "There is a door on your left and on your right." << endl;
	LINEOUT(What will you do?);
	getline(cin, answer);
	}
	
	if(answer == "left door"){ansNum = 1;} else if (answer == "right door"){ansNum = 2;} 
	else if (answer == "search room"){ansNum = 4;}
	else {ansNum = 5;}
	
	
	switch(ansNum){
		case 1:
			system("cls");
			cout << "You enter a room with a bookshelf on one wall and a chest on the other." << endl;
			cout << "What will you do?" << endl;
			getline(cin, answer);
			if(answer == "search chest" && !chestSearched){
				cout << "You search the chest!" << endl;
				cout << "You find a potion!" << endl;
				character.setPotion(1);
			} else if(answer == "search chest" && chestSearched){
				cout << "You already searched the chest." << endl;
			} else if(answer == "search bookshelf" && !bookshelfSearched){
				cout << "You search the bookshelf." << endl;
				cin.ignore();
				cout << "Looking at it, you see many old novels and tomes covered in dust." << endl;
				cout << "Theres one book that looks weird though." << endl;
				cout << "On closer inspection, you see that the book is called 'Gems R Us'" << endl;
				cout << "You go to grab it off the shelf and you hear a click as soon as you touch it." << endl;
				cin.ignore();
				cout << "Behind the bookshelf was a secret compartment containing the third gem!" << endl;
				cout << "You grab it." << endl;
				character.setGem3(true);
				gemFound = true;
			} else if(answer == "search bookshelf" && bookshelfSearched) {
				cout << "You already searched the bookshelf." << endl;
			} else {
				cout << "You do nothing." << endl;
			}
			LINEOUT(You leave the room.);
			cin.ignore();
			room1entered = true;
			break;
		case 2:
			system("cls");
			cout << "This room seems really empty." << endl;
			cout << "What will you do?" << endl;
			getline(cin, answer);
			if(answer == "search room"){
			cout << "Upon closer inspection you notice a switch on the far wall." << endl;
			cout << "You walk over to it and flip the switch." << endl;
			cin.ignore();
			cout << "Spikes shoot down from the ceiling and damage you for 5 health." << endl;
			character.setHp(-5);
			character.gameOver();
			cout << "Nobody ever looks up." << endl;
			} else if (answer == "look up") {
				cout << "You see some spikes waiting for their next victim." << endl;
				cout << "You wisely decide to leave the room" << endl;
			} else {
				cout << "Not knowing what else to do, you leave the room." << endl;
			}
			room2entered = true;
			cin.ignore();
			break;
		case 4:
			system("cls");
			LINEOUT(Theres nothing else for you to find.);
			break;
		default:
			LINEOUT(You just kinda stand there.);
			LINEOUT((Hit enter));
			cin.ignore();
	}//end of switch
	
	}//end of while loop
	cout << "When you come back into the center room, you notice a figure standing in the" << endl;
	cout << "middle of the room. He looks like a statue, but as you approach, he lunges at you." << endl;
	cin.ignore();
	
	//Knight fight!!!
	while (!knightDead)
	{
		//Clears console so it doesn't get cluttered
		system("cls");
		

		//This section deals with the knight attacking

		randomNum = (rand() % (4 - 1 + 1)) + 1;	//Generates a number 1-4
		if (randomNum == 1 || randomNum == 2 || randomNum == 3)//Allows for a 1 in 4 shot of the attack missing
		{
			cout << endl;	//Little bit of space
			//Determines if you have a shield or not and then subtracts damage
			cout << "The knight hit you for 2 damage!" << endl;
			if (character.getShield())
			{
				cout << "Your shield took a point of damage for you!" << endl;
				character.setHp(-1);
				character.gameOver();
			}
			else
			{
				character.setHp(-2);
				character.gameOver();
			}
				cout << "Your current HP is: " << character.getHp() << endl;
		}
		else
		{
			cout << endl;
			cout << "The knight's attack misses!" << endl;
		}
			cout << endl;
		//End of knight
		//Character choice
		cout << "What will you do?" << endl;
		cout << "1 - Attack \t 2 - Drink potion" << endl;
		cin >> combatNum;
		cout << endl;	//Little bit of space
		//Player's move is in this area
		switch (combatNum)
		{
			case 1:
				randomNum = (rand() % (6 - 1 + 1)) + 1;	//Generates a number 1-6
				if (randomNum != 6)//theres a 1 in 6 chance that your attack misses
				{
					if (character.getSword())
					{
						cout << "Your attack does 3 damage!" << endl;
						knightHealth = knightHealth - 3;
						cout << "The knight's current health is: " << knightHealth;
						cout << endl;
					}
					else
					{
						cout << "Your attack does 2 damage!" << endl;
						knightHealth = knightHealth - 2;
						cout << "The knight's current health is: " << knightHealth;
						cout << endl;
					}
				}
				else
				{
					cout << "Your attack misses!" << endl;
					cout << endl;
				}
				break;
			case 2:
				if (character.getPotion() != 0)
				{
					cout << "You used a potion!" << endl;
					character.setHp(20);
					cout << "Your current HP is: " << character.getHp() << endl;
				}
				else
				{
					cout << "You don't have any potions left!" << endl;
					cout << "Your current HP is: " << character.getHp() << endl;
				}
					break;
			default:
				cout << "You think standing there like an idiot is a bad choice." << endl;
				cout << "(Try Again)" << endl;
		}
		cin.ignore();	//Helps pause it
		cin.ignore();
		//Checks if knight's health is 0 or less and exits the while loop if it is
		if (knightHealth <= 0)
		{
			knightDead = true;
		}
}
	cout << "You killed the knight! Congratulations!" << endl;
	cin.ignore();
	cout << "You see a door appear on the wall behind the knight." << endl;
	cout << "You walk through the door." << endl;
	return roomComplete;
}
