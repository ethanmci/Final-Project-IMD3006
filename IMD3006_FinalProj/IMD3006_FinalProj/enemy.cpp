#include "enemy.h"
#include <time.h>

string Enemy::getVis()
{
	if(!dead)
		return this->visuals[selEnemyType];
	else
		return this->visualsDeadVar[selEnemyType];
}

string Enemy::getEnemyType()
{
	return enemyTypes[selEnemyType];
}

Enemy::Enemy(string newWord)
{
	this->dead = false;
	this->selWord = newWord;
	this->selEnemyType = rand() % 3;
}

void Enemy::update()
{
	bool letterFound;
	for (int i = 0; i < selWord.size(); i++) {
		letterFound = false;
		for (int j = 0; j < pastGuesses.size(); j++) {
			if (pastGuesses[j] == selWord[i]) {
				letterFound = true;
			}
		}
		if (letterFound == true && i == selWord.size() - 1) {
			this->dead = true;
		}
		else if (letterFound == false) {
			//letter not found, breaking the loop
			break;
		}
	}
}
