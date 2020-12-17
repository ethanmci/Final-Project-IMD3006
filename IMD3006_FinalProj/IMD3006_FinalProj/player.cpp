#include "player.h"
#include "enemy.h"
#include <iostream>
#include <algorithm>

Player::Player()
{
	this->health = 10;
}

string Player::getVis()
{
	return healthVis[10 - health];
}

string Player::getInv(Enemy* currEnemy)
{
	cout << "===INVENTORY===\n";
	for (int i = 0; i < inventory.size(); i++) {
		cout << (i + 1) << " --> ";
		cout << inventory[i]->names[inventory[i]->selPotion] << endl;
		cout << "-----------------\n";
	}

	cout << "\nenter the number of the item you want to use, or type 'back' to return to combat\n";
	string selection;
	while (1) {
		cin >> selection;
		transform(selection.begin(), selection.end(), selection.begin(), tolower);
		try {
			int strToInt = stoi(selection, nullptr, 10) - 1;
			if (strToInt < this->inventory.size() && strToInt >= 0) {
				string out;
				out = this->inventory[strToInt]->applyEffect(this, currEnemy);
				this->inventory.erase(inventory.begin() + strToInt);
				return out;
			}
			else {
				cout << "invalid invintory slot\n";
			}
		}
		catch (...) {
			//input cannot be converted, assume player is entering a command
			if (selection == "back") {
				return "";
			}
			else {
				cout << "invalid input\n";
			}
		}

	}
}

void Player::updateHealth(int updateAmt)
{
	if (this->health + updateAmt >= 0 && this->health + updateAmt < 11) {
		//"clamps" health value at 0
		this->health += updateAmt;
	}
	else if (this->health + updateAmt >= 11) {
		//clamping max health at 10
		this->health = 10;
	}
}
