#include "Item.h"
#include "player.h"
#include "enemy.h"

string Item::getVis()
{
	return this->visuals[selPotion];
}

void Item::applyEffect(Player* player, Enemy* enemy)
{
	if (selPotion == 0) {
		//potion of healing
		player->updateHealth(2);
	}
	else if (selPotion == 1) {
		//potion of revealing
		bool revealed = false;
		while (!revealed) {
			enemy->selWord[rand() % enemy->selWord.length()];
		}
	}
	else if (selPotion == 2) {
		enemy->dead = true;
	}
}

void Item::encounterDisplay()
{
	cout << "You found a" << this->names[this->selPotion] << "!\n";
	cout << this->visuals[this->selPotion] << endl;
	cout << "access it in your inventory by typing 'inv' during a fight!\n";
	cout << this->descriptions[this->selPotion] << endl;
}

Item::Item()
{
	this->selPotion = rand() % 2;
}

