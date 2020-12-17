#pragma once
#include "Item.h"
#include <string>
#include <vector>

using namespace std;

class Enemy;
class Player
{
public:
	//variables / data
	int health;
	vector<Item*> inventory;
    string healthVis[7] = {
R"(
  +---+
  |   |
      |
      |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
      |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)"/*,
R"(
   _____          __  __ ______    ______      ________ _____  
  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
 | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
 | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
 | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\)"*/
	
	};
	
	//methods
	string getVis();
	string getInv(Enemy* currEnemy);
	Player();
	void updateHealth(int updateAmt);
};