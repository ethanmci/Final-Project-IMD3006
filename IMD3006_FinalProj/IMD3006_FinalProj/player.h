#pragma once
#include <string>
using namespace std;
class Player
{
public:
	//variables / data
	int health;
	Player();
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
)"
	
	};
	
	//methods
	string getVis();
	void updateHealth(int updateAmt);
};

