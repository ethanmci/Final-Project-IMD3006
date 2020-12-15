#pragma once
#pragma execution_character_set("utf-8")
#include <string>
using namespace std;
class Player;
class Enemy;
class Item
{
public:
	string visuals[3] = { 
R"(
 [++++]
   ||
  /--\
 /=++=\
/______\
)",
R"(
 [????]
   ||
  /--\
 /=??=\
/______\
)",
R"(
 [====]
   ||
  /--\
 /kill\
/______\
)"
	};
	string names[3] = { "potion of healing", "potion of revealing", "potion of damage dealing" };
	string descriptions[3] = {
	"use this potion to restore life!",
	"use this potion to reveal an enemys letter",
	"use this potion to instantly kill an enemy"
	};
	int selPotion;

	string getVis();
	void applyEffect(Player* player, Enemy* enemy);
	void encounterDisplay();
	Item();
};

