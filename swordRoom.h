//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19
//includes another timed answer, kills you if you dont type grab sword in time

#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <stdio.h>
#include <time.h>
#include <string>

//Building strings
#define LINEOUT(str) cout << #str << endl

#pragma once

bool swordFunction(Player1& character)
{
	bool roomComplete = false;
	string answer = "";
	time_t seconds;
	time_t seconds2;
	
	system("cls");
	cout << "You see the sword of legend in the center of the room." << endl;
	LINEOUT(A beam of light cascades from the ceiling and illuminates the sword.);
	cout << "As you walk up to the sword, the gems fly from the previous room." << endl;
	LINEOUT(and land in the pommel of the sword. As soon as the gems land in the sword);
	LINEOUT(the old man appears with a warning:);
	cout << endl;
	cout << "Are you ready to rule?? Wielding this sword is a heavy burden." << endl;
	cout << "Grab the sword only if you are sure you're ready." << endl;
	cout << "What will you do?" << endl;
	seconds = time(NULL);
	getline(cin, answer);
	if(answer == "grab sword"){
		seconds2 = time(NULL);
		if(seconds2 - seconds <= 7){
			cout << "You grab the sword and begin your rule." << endl;
			roomComplete = true;
		} else {
			cout << "'You took too long to decide. You are not worthy,' the old man says." << endl;
			cout << "He smites you." << endl;
		character.setHp(-20);
		character.gameOver();
		}
	} else {
		cout << "'Then you are not worthy,' the old man says." << endl;
		cout << "He smites you." << endl;
		character.setHp(-20);
		character.gameOver();
	}
	
	return roomComplete;	
}
