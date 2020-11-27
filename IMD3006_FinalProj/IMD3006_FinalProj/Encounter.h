#pragma once
#include "enemy.h"
using namespace std;
class Encounter
{
public:
	virtual void getEncoutnerVis();
};

class ItemEncounter : public Encounter {
public:
	//item variable should be here!
	void getEncounterVis();
};

class EnemyEncounter : public Encounter {
public: 
	Enemy* enemy;

	EnemyEncounter(string word);
	void getEncounterVis();
};

