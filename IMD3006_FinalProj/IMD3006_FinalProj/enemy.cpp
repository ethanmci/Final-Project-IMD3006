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
