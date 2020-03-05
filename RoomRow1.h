//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19
//row 1 function has three rooms in it, it holds a sword, a potion and gem 1
 
#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <string>

//Building strings
#define LINEOUT(str) cout << #str << endl

#pragma once

bool row1Function(Player1& character)
{
	string answer = "";
	int count = 0; //Incremented only once, but still useful
	bool room1entered = false;
	bool room2entered = false;
	bool roomComplete = false;
	bool row1Potion = false;
	
	system("cls");
	cout << "You come to a room with a locked door on the center wall in front of you" << endl;
	cout << "one door on the left, and one door on the right." << endl;
	
	while(!roomComplete){
	
	int ansNum = 0;
	if(count == 0){
	count++;
	LINEOUT(What will you do?);
	getline(cin, answer);
	} else {
	system("cls");
	ansNum = 0;
	LINEOUT(Youre back in the middle room with the three doors.);
	cout << "There is a door on your left, on your right, and a locked door in the middle." << endl;
	LINEOUT(What will you do?);
	getline(cin, answer);
	}
	
	if(answer == "left door"){ansNum = 1;} else if (answer == "right door"){ansNum = 2;} 
	else if(answer == "locked door"){ansNum = 3;} else if (answer == "search room"){ansNum = 4;}
	else {ansNum = 5;}
	
	
	switch(ansNum){
		case 1:
			system("cls");
			if(!character.getSword()){
			LINEOUT(There is a sword in the middle of the room. Its not the one you were);
			cout << "looking for, but its a sword none the less. You pick it up." << endl;
			character.setSword(true);
			} else {
			cout << "Surprisingly, theres not another sword here for you to get" << endl;
			}
			LINEOUT(You leave the room.);
			cin.ignore();
			room1entered = true;
			break;
		case 2:
			system("cls");
			if(!character.getGem1()){
			LINEOUT(Theres a shining gem in the middle of the room.);
			cout << "You feel like you shouldnt touch it, but out of nowhere" << endl;
			LINEOUT(a voice sounding like Harrison Ford says:);
			LINEOUT(-This belongs in a museum-);
			cout << "You then remember it actually probably belongs to the sword," << endl;
			LINEOUT(so you pick it up.);
			character.setGem1(true);
			} else {
			LINEOUT(You already got the gem.);
			}
			LINEOUT(You leave the room.);
			cin.ignore();
			room2entered = true;
			break;
		case 3:
			system("cls");
			if(room1entered && room2entered){
			cout << "As you approach, the door unlocks itself. Almost as if it can" << endl;
			LINEOUT(sense youve been in every room.);
			LINEOUT(You walk through the door.);
			roomComplete = true;
			cin.ignore();
			} else {
			LINEOUT (This door is locked. You have no idea how to open it.);
			}
			break;
		case 4:
			system("cls");
			if(!row1Potion){
			LINEOUT(You found a potion on the ground!);
			LINEOUT(One potion has been added to your inventory.);
			character.setPotion(1);
			row1Potion = true;
			} else {
			LINEOUT(Theres nothing else for you to find.);
			}
			break;
		default:
			LINEOUT(You just kinda stand there.);
			LINEOUT((Hit enter));
			cin.ignore();
	}//end of switch
	
	}//end of while loop
	return roomComplete;
}
