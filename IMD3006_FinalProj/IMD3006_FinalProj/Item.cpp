#include "Item.h"
#include "player.h"

string Item::getVis()
{
	return this->visual;
}

void Item::applyEffect(Player* player)
{
}

Item::Item()
{
	this->name = "name";
	this->effect = "EFFECT_NAME";
}

