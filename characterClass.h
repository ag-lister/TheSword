//Coded by Andy Lister, aglister@dmacc.edu, 11/26/19


#ifndef characterClass
#define characterClass

#include <iostream>
#include <string>
using namespace std;

class Player1
{
	private:
		int hp;
		//These are for inventory management
		bool sword; //changes to true if you find it
		bool shield; //changes to true if you find it
		int potion; //keeps a running total
		bool gem1; //changes to true if you find it
		bool gem2; //changes to true if you find it
		bool gem3; //changes to true if you find it
		bool gem4; //changes to true if you find it
	
	public:
		Player1(){hp = 20; sword = false; shield = false; potion = 0; gem1 = false;
					gem2 = false; gem3 = false; gem4 = false;} //default constructor
		
		//setters
		void setHp(int s) {hp = hp + s; if (hp > 20){hp = 20;}};//running total. Allows us to put in negative or positive numbers and have it work just fine
		void setSword(bool s) {sword = s;};
		void setShield(bool s){shield = s;};
		void setPotion(int s){potion = potion + s;}; //running total
		void setGem1(bool s){gem1 = s;}
		void setGem2(bool s){gem2 = s;}
		void setGem3(bool s){gem3 = s;}
		void setGem4(bool s){gem4 = s;}
		
		//getters
		int getHp(){return hp;};
		bool getSword(){return sword;};
		bool getShield(){return shield;};
		int getPotion(){return potion;};
		bool getGem1(){return gem1;}
		bool getGem2(){return gem2;}
		bool getGem3(){return gem3;}
		bool getGem4(){return gem4;}
		
		//shows inventory when you call this in a cout statement.
		//only shows potions until there is a sword/shield there as well.
		string showInventory(){
			string inventory = "";
			if (sword){inventory = inventory + "- 1 sword \n";}
			if (shield){inventory = inventory + "- 1 shield \n";}
			inventory = inventory + "- " + to_string(potion) + " potion(s) \n";
			if (gem1){inventory = inventory + "- Gem 1 \n";}
			if (gem2){inventory = inventory + "- Gem 2 \n";}
			if (gem3){inventory = inventory + "- Gem 3 \n";}
			if (gem4){inventory = inventory + "- Gem 4 \n";}
			return inventory;
			}
		
		//checks for hp each time you call it and ends the game if their hp is 0 or below	
		void gameOver(){
			if(hp <= 0){
				system("cls");
				cout << "Your HP is " << hp << endl;
				cout << "As you draw your last breath, you reflect on your life." << endl;
				cout << "It was good, but it would have been so much better if you had" << endl;
				cout << "found the Sword. Better luck to the next person to try." << endl;
				cout << endl;
				cout << "---- GAME OVER ----" << endl;
				exit(-1);
				system("pause");
			}
		}
		
};

#endif
