//Coded by Andy Lister, aglister@dmacc.edu, 09/30/19
//opening room for the dungeon, includes the time requirement
//player has 5 seconds to type in enter dungeon before something happens


#include "characterClass.h"	//needed to pass the class as a reference
#include <string>
#include <stdio.h>
#include <time.h>

#pragma once

void openingChamber(Player1& character){
	string answer = "";
	time_t seconds;
	time_t seconds2;
	
	system("cls");
	cout << "Ever since you were a child you heard about a mythical" << endl;
	cout << "sword that when acquired allowed you to rule the world." << endl;
	cout << endl;
	cout << "You thought it was a myth until a local madman started" << endl;
	cout << "rhyming about gems on a full moon. He said:" << endl;
	cout << endl;
	cout << "Find the four gems, shrouded in stone," << endl;
	cout << "only there can you prove your worth." << endl;
	cout << "Find the sword with gems in bone," << endl;
	cout << "and claim the power yours since birth." << endl;
	cin.ignore();
	
	cout << "You figured out that 'shrouded in stone' probably means this dungeon" << endl;
	cout << "that you found by the light of the full moon, but you're not sure if" << endl;
	cout << "you want to enter." << endl;
	cout << "What will you do?" << endl;
	seconds = time(NULL);
	getline(cin, answer);
	if(answer == "enter dungeon"){
		seconds2 = time(NULL);
		if(seconds2 - seconds <= 5){
			cout << "You enter the dungeon." << endl;
			cin.ignore();
		} else {
			cout << "You hear a voice boom from the deep:" << endl;
			cout << "HESITATION IS NOT TOLERATED. YOU ARE WEAK." << endl;
			cout << "You feel the ground shift beneath you and you fall into a spike trap." << endl;
			cout << "Your last thought before you fall is:" << endl;
			cout << "-I cant believe I took too long to answer-" << endl;
			cin.ignore();
			character.setHp(-20);
			character.gameOver();
		}
	} else {
		character.setHp(-20);
		character.gameOver();
	}
	
}
