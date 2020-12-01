#pragma once
#include "player.h"
class Item
{
public:
	string visual;
	string name;
	string effect;

	string getVis();
	void applyEffect(Player player);
};

