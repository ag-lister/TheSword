//Coded by Andy Lister, aglister@dmacc.edu, 12/1/19
//row 2 has three rooms in it, it holds the shield and gem 2

#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <string>

//Building strings
#define LINEOUT(str) cout << #str << endl

#pragma once

bool row2Function(Player1& character)
{
	string answer = "";
	int count = 0; //Incremented only once, but still useful
	bool room1entered = false;
	bool room2entered = false;
	bool roomComplete = false;
	
	system("cls");
	cout << "You come to a another room with a locked door on the center wall in front of you" << endl;
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
			if(!character.getGem2()){
			LINEOUT(Theres a shining gem in the middle of the room.);
			cout << "Remembering that these gems are for the sword," << endl;
			LINEOUT(you hurriedly snatch up the gem.);
			character.setGem2(true);
			} else {
			LINEOUT(Dude theres no gem in here.);
			}
			LINEOUT(You leave the room.);
			cin.ignore();
			room1entered = true;
			break;
		case 2:
			system("cls");
			if(!character.getShield()){
			LINEOUT(There is a shield hanging on the wall in front of you.);
			LINEOUT(You pick it up.);
			character.setShield(true);
			} else {
			cout << "Surprisingly, theres not another shield here for you to get." << endl;
			}
			LINEOUT(You leave the room.);
			cin.ignore();
			room2entered = true;
			break;
		case 3:
			system("cls");
			if(room1entered && room2entered){
			cout << "As you approach, you hear a booming voice enter your mind." << endl;
			cout << "ANSWER THIS RIDDLE AS SUCH AND YOU MAY PASS," << endl;
			cout << "BUT BE CAREFUL, THIS NEXT ROOM MAY BE YOUR LAST." << endl;
			cout << endl;
			cout << "NOBODY LIKES ME, I'M MEANT TO CONFUSE AND CONFOUND," << endl;
			cout << "BUT KNOW ME AND YOUR CLEVERNESS WILL BE THE TALK OF THE TOWN." << endl;
			cout << "WHAT AM I?" << endl;
			string riddle = "";
			getline(cin, riddle);
			if(riddle == "a riddle" || riddle == "riddle" || riddle == "A RIDDLE"){
			cout << "Yup." << endl;
			roomComplete = true;
			cout << endl;
			cout << "The door unlocks and you walk through it." << endl;
			} else {
				cout << "Nope." << endl;
				cout << endl;
				cout << "You step away from the door." << endl;
			}
			cin.ignore();
			} else {
			LINEOUT (This door is locked. You have no idea how to open it.);
			}
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
	return roomComplete;
}
