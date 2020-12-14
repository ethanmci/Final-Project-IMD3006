#include "Level.h"

Level::Level(int newDiff, string *wordList)
{
	this->difficulty = newDiff;
	this->posInLvl = 0;
	this->levelComplete = false;
	for (int i = 0; i < 10; i++) {
		if (i % 4 == 0 && i != 0) {
			this->encounters.insert(this->encounters.begin(), new ItemEncounter());
		}
		else {
			string selWord;
			bool validWord = false;
			//creating words for enemy encounters based on difficulty
			while (!validWord) {
				selWord = wordList[rand() % 980 + 1];
				if (this->difficulty == 1) {
					if (selWord.length() <= 4)
						validWord = true;
				}
				else if (this->difficulty == 2) {
					if (selWord.length() <= 5)
						validWord = true;
				}
				else if (this->difficulty == 3) {
					if (selWord.length() <= 6)
						validWord = true;
				}
				else if (this->difficulty == 4) {
					if (selWord.length() <= 7)
						validWord = true;
				}
				else {
					if (selWord.length() > 6)
						validWord = true;
				}
			}
			this->encounters.insert(this->encounters.begin(), new EnemyEncounter(selWord));
		}
	}
}

Encounter* Level::currentEncounter()
{		
	return this->encounters[posInLvl];

}

void Level::nextEncounter()
{
	if ((posInLvl + 1) < encounters.size()) {
		posInLvl++;
	}
	else {
		this->levelComplete = true;
	}
}
