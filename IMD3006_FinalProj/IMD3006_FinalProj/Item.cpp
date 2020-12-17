#include "Item.h"
#include "player.h"
#include "enemy.h"

string Item::getVis()
{
	return this->visuals[selPotion];
}

string Item::applyEffect(Player* player, Enemy* enemy)
{
	if (selPotion == 0) {
		//potion of healing
		player->updateHealth(2);
		return "the player has been healed from the potion!\n";
	}
	else if (selPotion == 1) {
		//potion of revealing
		bool revealed = false;
		char newLetter;
		while (!revealed) {
			newLetter = enemy->selWord[rand() % enemy->selWord.length()];
			revealed = true;
			for (int i = 0; i < enemy->pastGuesses.size(); i++) {
				if (newLetter == enemy->pastGuesses[i])
					revealed = false;
			}
		}
		enemy->pastGuesses.push_back(newLetter);
		return "the enemy has had a letter revealed with the potion!\n";
	}
	else if (selPotion == 2) {
		enemy->dead = true;
		return "the enemy has been killed with the potion!\n";
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
	this->selPotion = rand() % 3;
}

