#include "player.h"
#include <iostream>

Player::Player()
{
	this->health = 7;
}

string Player::getVis()
{
	return healthVis[7 - health];
}

string Player::getInv()
{
	cout << "===INVENTORY===\n";
	for (int i = 0; i < inventory.size(); i++) {
		cout << (i + 1) << " --> ";
		cout << inventory[i]->names[inventory[i]->selPotion] << endl;
		cout << "---------------\n";
	}
	
	cout << "\nenter the number of the item you want to use, or type 'back' to return to combat\n";
	string selection;
	while (1) {
		cin >> selection;
		if (selection == "back") {
			system("cls");
			return "";
		}
		else {
			system("cls");
			return "pretend a potion was applied ok?";
		}
	}
	//process selection here!
}

void Player::updateHealth(int updateAmt)
{
	//"clamps" health value at 0
	if (this->health + updateAmt >= 0) {
		this->health += updateAmt;
	}
}
