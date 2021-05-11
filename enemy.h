#pragma once

#include "entity.h"
#include "random.h"
#include "player.h"

class enemy : public entity
{
public:
	float movementSpeed = 3.5;
	float movementLenght = 20;
	int attackDamage = 5;
	int counterWalking = 0;
	int counterAttack = 0;
	int counterAttack2 = 0;
	int direction = 0; // 1 - down, 2 - up, 3 - left, 4 - right
	int counterRoad;
	int hp = 100;
	bool alive = true;
	sf::Clock animacja;
	bool animating{ false };
	bool animating2{ false };
	bool animating3{ false };
	bool animating4{ false };
	bool attack{ false };

	friend class player;

	enemy();
	void update();
	void updateMovementRight(int postac);
	void updateMovementLeft(int postac);
	void attackLeft(int postac);
	void attackRight(int postac);
};

