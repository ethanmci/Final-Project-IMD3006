#include "Level.h"

Level::Level(int newDiff, string *wordList)
{
	this->difficulty = newDiff;
	this->posInLvl = 0;
	for (int i = 0; i < 1; i++) {
		if (i % 4 == 0 && i != 0) {
			this->encounters = new ItemEncounter();
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
					if (selWord.length() <= 6)
						validWord = true;
				}
				else {
					if (selWord.length() > 4)
						validWord = true;
				}
			}
			this->encounters = new EnemyEncounter(selWord);
		}
	}
}

Encounter* Level::currentEncounter()
{
	return this->encounters;
}
