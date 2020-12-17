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
    string healthVis[10] = {
R"(





=========
)",
R"(
      +
      |
      |
      |
      |
      |
=========
)",
R"(
  +---+
      |
      |
      |
      |
      |
=========
)",
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
)"
};
	
	//methods
	string getVis();
	string getInv(Enemy* currEnemy);
	Player();
	void updateHealth(int updateAmt);
};