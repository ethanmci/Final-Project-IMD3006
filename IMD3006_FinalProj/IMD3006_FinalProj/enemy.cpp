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

void Enemy::display()
{
	cout << "Past Guesses: [";
	for (int g = 0; g < this->pastGuesses.size(); g++) {
		cout << this->pastGuesses[g] << ", ";
	}
	cout << "]";
	cout << endl << this->selWord << endl; //debugging output
	this->update();
	cout << this->getVis();
	if (this->pastGuesses.size() == 0)
		cout << "a " << this->getEnemyType() << " approaches!\n";
	else if(this->dead)
		cout << "the " << this->getEnemyType() << " has been defeated!\n";
	cout << "word: ";
	for (int x = 0; x < this->selWord.length(); ++x)
	{
		bool isGuessed = false;
		for (int j = 0; j < this->pastGuesses.size(); j++) {
			if (this->selWord[x] == this->pastGuesses[j]) {
				cout << this->selWord[x] << " ";
				isGuessed = true;
			}
		}

		if (!isGuessed)
			cout << "_ ";
	}
	cout << endl;
}
