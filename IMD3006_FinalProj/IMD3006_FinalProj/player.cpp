#include "player.h"

Player::Player()
{
	this->health = 7;
}

string Player::getVis()
{
	return healthVis[7 - health];
}

void Player::updateHealth(int updateAmt)
{
	//"clamps" health value at 0
	if (this->health + updateAmt >= 0) {
		this->health += updateAmt;
	}
}
