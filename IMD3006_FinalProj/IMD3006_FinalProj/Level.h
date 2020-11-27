#pragma once
#include "Encounter.h"
#include <string>
#include <vector>
using namespace std;
class Level
{
public:
	int posInLvl;
	int difficulty;
	Encounter** encounters[10];

	//functions
	Level(int newDiff, string* wordList);
	Encounter* currentEncounter();
};

