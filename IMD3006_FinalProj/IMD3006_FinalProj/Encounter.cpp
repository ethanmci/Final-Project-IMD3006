#include "Encounter.h"
#include <iostream>

void ItemEncounter::getEncounterVis()
{
	cout << "this is an item";
}

EnemyEncounter::EnemyEncounter(string word)
{
	this->enemy = new Enemy(word);
}

void EnemyEncounter::getEncounterVis() const
{
}


void Encounter::getEncoutnerVis() 
{
	//do nothing lol
}
