#pragma once

#include "entity.h"

class playerb : public entity
{
public:
	float movementSpeed = 3.5;
	int attackDamage = 5;
	int counterWalking = 0;
	int counterAttack = 0;
	int counterAttack2 = 0;
	int hp = 100;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right
	sf::Clock animacja;
	bool animating{ false };
	bool animating2{ false };
	bool animating3{ false };
	bool animating4{ false };
	bool alive = true;


	playerb();
	void update();
	void updateMovement(int postac);
	void updateMovementR(int postac);
	void displayHP();
};
