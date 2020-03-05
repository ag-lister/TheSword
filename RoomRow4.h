//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19
//3 rooms, the 4th gem, a potions room, and an old man who kills you if you missed a gem
 
#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <string>

//Building strings
#define LINEOUT(str) cout << #str << endl

#pragma once

bool row4Function(Player1& character)
{
	string answer = "";
	int count = 0; //Incremented only once, but still useful
	bool room1entered = false;
	bool room2entered = false;
	bool roomComplete = false;
	bool row1Potion = false;
	bool gemFound = false;
	
	system("cls");
	cout << "You come to a room with another door on the left and one on the right" << endl;
	
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
			if(!character.getGem4()){
				LINEOUT(You see the fourth gem just like...laying there.);
				LINEOUT(You pick it up.);
				character.setGem4(true);
				gemFound= true;
			} else {
				LINEOUT(Theres no more gems here. Go away.);
			}
			LINEOUT(You leave the room.);
			cin.ignore();
			break;
		case 2:
			system("cls");
			cout << "You found a stack of potions!" << endl;
			if(character.getPotion() < 5){
				cout << "You add one to your inventory!" << endl;
				character.setPotion(1);
			} else {
				cout << "You can't carry any more potions!" << endl;
			}
			LINEOUT(You leave the room.);
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
	
	cout << "Leaving the room, you see an old man standing before you." << endl;
	cout << "He says:" << endl;
	cout << endl;
	cout << "So you're here for the sword..." << endl;
	cout << "*he looks you up and down*" << endl;
	int gemCount = 0;
	if (character.getGem1()){
		gemCount++;
	}
	if (character.getGem2()){
		gemCount++;
	}
	if (character.getGem3()){
		gemCount++;
	}
	if (character.getGem4()){
		gemCount++;
	}
	
	if(count == 4){
		cout << "I see you have all four gems. Very well, you may pass." << endl;
		cout << endl;
		cout << "A door opens behind him and you walk through it." << endl;
		cin.ignore();
		roomComplete = true;
	} else {
		cout << "You are not worthy." << endl;
		cout << endl;
		cout << "He smites you where you stand." << endl;
		cin.ignore();
		character.setHp(-20);
		character.gameOver();
	}
	
	return roomComplete;
}
