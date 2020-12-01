#include "Encounter.h"
#include <iostream>



void ItemEncounter::getEncounterVis()
{
	//this->item->getVis();
}

ItemEncounter::ItemEncounter()
{
	encounterType = "ITEM";
}

EnemyEncounter::EnemyEncounter(string word)
{
	encounterType = "ENEMY";
	this->enemy = new Enemy(word);
}

void EnemyEncounter::getEncounterVis() 
{
	this->enemy->getVis();
}