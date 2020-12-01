#pragma once
#include "enemy.h"
#include "Item.h"
using namespace std;
class Encounter
{
public:
	virtual void getEncounterVis() = 0;
	string encounterType;
};

class ItemEncounter : public Encounter {
public:
	Item* item;
	void getEncounterVis() override;
	ItemEncounter();
};

class EnemyEncounter : public Encounter {
public: 
	Enemy* enemy;

	EnemyEncounter(string word);
	void getEncounterVis() override;
};

