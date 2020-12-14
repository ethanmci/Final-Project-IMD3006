#pragma once
#include <map>
#include <string>
using namespace std;
class Player;
class Item
{
public:
	string visual = {};
	string name;
	string effect;

	string getVis();
	void applyEffect(Player* player);
	Item();
};

