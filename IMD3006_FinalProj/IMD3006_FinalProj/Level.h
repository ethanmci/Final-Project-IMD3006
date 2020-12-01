#pragma once
#include "Encounter.h"
#include <string>
#include <vector>
#include <variant>
using namespace std;
class Level
{
public:
	int posInLvl;
	int difficulty;
	vector<Encounter*> encounters;

	//functions
	Level(int newDiff, string* wordList);
	Encounter* currentEncounter();
};

