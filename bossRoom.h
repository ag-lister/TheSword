//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19
//boss room, includes combat, dropping gems

#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <string>

//Building strings
#define LINEOUT(str) cout << #str << endl

#pragma once

bool bossFunction(Player1& character)
{
	bool roomComplete = false;
	
	system("cls");
	cout << "Upon entering the room, you see a giant statue with four gem slots in the base." << endl;
	cout << "Seeing the slots, you scramble to take the gems out of your bag." << endl;
	cout << "In your hurry, they all fall out." << endl;
	character.setGem1(false);
	character.setGem2(false);
	character.setGem3(false);
	character.setGem4(false);
	cin.ignore();
	cout << "Right before they hit the floor, they all stop" << endl;
	cout << "as if some magic invisible hand caught them." << endl;
	cout << "They slowly rise and start spinning in a circle until the gems" << endl;
	cout << "all line up in order with the slots." << endl;
	cin.ignore();
	cout << "As they settle into place in the gem slots, the statue comes to life and attacks." << endl;
	cin.ignore();
	
	//Knight fight
	int knightHealth = 60;
	bool knightDead = false;
	int combatNum = 0;
	unsigned seed = time(0);
	srand(seed);
	int randomNum = 0; //used later
	
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
			cout << "The knight hit you for 3 damage!" << endl;
			if (character.getShield())
			{
				cout << "Your shield took a point of damage for you!" << endl;
				character.setHp(-2);
				character.gameOver();
			}
			else
			{
				character.setHp(-3);
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
						cout << "Your attack does 4 damage!" << endl;
						knightHealth = knightHealth - 4;
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
	cout << "The knight crumbles to stone." << endl;
	cout << "As the dust clears, you see the same old man from before." << endl;
	cout << "'The way is now open to you, sire.'" << endl;
	cout << endl;
	cout << "You see a door open at the far end of the room." << endl;
	cout << "You walk through it." << endl;
	
	roomComplete = true;
	return roomComplete;
	
}
