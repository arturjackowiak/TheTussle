#include "enemy.h"
#include "player.h"


enemy::enemy()
{
	rect.setPosition(500, 125);
	rect.setSize(sf::Vector2f(63, 90));
	sprite.setTextureRect(sf::IntRect(22, 149, 65, 90));
	sprite.setScale(sf::Vector2f(1, 1));
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}


void enemy::updateMovementLeft(int postac) {
	if (postac == 0) {
		if (direction == 3 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x >= 0)
		{
			attack = false;
			rect.setSize(sf::Vector2f(63, 95));
			rect.move(-movementSpeed, 0);


			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(28, 145, 56, 93));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(92, 144, 54, 84));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(154, 143, 59, 95));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(220, 144, 69, 95));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(297, 145, 70, 93));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(376, 150, 62, 89));
		}

		else if (direction == 4 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x <= 550)
		{
			attack = false;
			rect.move(movementSpeed, 0);
			rect.setSize(sf::Vector2f(63, 95));

			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(643, 151, 63, 89));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(715, 146, 63, 93));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(785, 145, 63, 95));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(854, 144, 54, 95));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(916, 145, 54, 94));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(978, 146, 61, 93));
		}

		else
		{
			attack = false;
		}

		counterWalking++;
		if (counterWalking == 11) {
			counterWalking = 0;
		}

		counterRoad++;
		if (counterRoad >= movementLenght)
		{
			direction = generateRandom(4);
			counterRoad = 0;
		}
	}

	if (postac == 1) {
		if (direction == 3 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x >= 0)
		{
			attack = false;
			rect.setSize(sf::Vector2f(70, 100));
			rect.move(-movementSpeed, 0);

			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(516, 14, 76, 97));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(432, 13, 76, 98));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(346, 14, 78, 103));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(274, 16, 67, 99));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(210, 17, 58, 98));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(138, 17, 66, 97));
		}

		else if (direction == 4 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x <= 550)
		{
			attack = false;
			rect.setSize(sf::Vector2f(70, 100));
			rect.move(movementSpeed, 0);
			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(540, 136, 73, 100));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(461, 134, 74, 101));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(373, 136, 82, 104));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(305, 137, 62, 102));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(247, 137, 53, 102));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(181, 137, 61, 101));
		}

		else
		{
			attack = false;
		}

		counterWalking++;
		if (counterWalking == 11) {
			counterWalking = 0;
		}

		counterRoad++;
		if (counterRoad >= movementLenght)
		{
			direction = generateRandom(4);
			counterRoad = 0;
		}
	}

}


void enemy::updateMovementRight(int postac) {
	if (postac == 0) {
		if (direction == 3 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x >= 0)
		{
			attack = false;
			rect.setSize(sf::Vector2f(63, 90));
			rect.move(-movementSpeed, 0);

			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(660, 150, 63, 90));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(731, 146, 61, 93));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(800, 145, 54, 94));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(862, 144, 54, 95));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(924, 145, 61, 94));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(993, 146, 63, 93));
		}

		else if (direction == 4 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x <= 550)
		{
			attack = false;
			rect.move(movementSpeed, 0);
			rect.setSize(sf::Vector2f(63, 90));

			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(22, 149, 65, 90));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(94, 144, 71, 94));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(172, 143, 68, 96));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(248, 142, 60, 96));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(315, 142, 55, 95));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(376, 142, 58, 95));
		}

		else
		{
			attack = false;
		}

		counterWalking++;
		if (counterWalking == 11) {
			counterWalking = 0;
		}

		counterRoad++;
		if (counterRoad >= movementLenght)
		{
			direction = generateRandom(8);
			counterRoad = 0;
		}
	}

	if (postac == 1) {
		if (direction == 3 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x >= 0)
		{
			attack = false;
			rect.move(-movementSpeed, 0);
			rect.setSize(sf::Vector2f(70, 100));
			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(552, 13, 76, 98));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(634, 13, 78, 103));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(719, 16, 68, 100));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(791, 17, 58, 98));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(855, 17, 67, 97));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(469, 13, 76, 101));
		}

		else if (direction == 4 && !animating && !animating2 && !animating3 && !animating4 && sprite.getPosition().x <= 550)
		{
			attack = false;
			rect.move(movementSpeed, 0);
			rect.setSize(sf::Vector2f(70, 100));

			if (counterWalking == 0)
				sprite.setTextureRect(sf::IntRect(446, 135, 73, 101));

			if (counterWalking == 2)
				sprite.setTextureRect(sf::IntRect(536, 134, 73, 99));

			if (counterWalking == 4)
				sprite.setTextureRect(sf::IntRect(605, 137, 82, 103));

			if (counterWalking == 6)
				sprite.setTextureRect(sf::IntRect(691, 136, 65, 103));

			if (counterWalking == 8)
				sprite.setTextureRect(sf::IntRect(761, 136, 52, 103));

			if (counterWalking == 10)
				sprite.setTextureRect(sf::IntRect(818, 137, 61, 100));
		}

		else
		{
			attack = false;
		}

		counterWalking++;
		if (counterWalking == 11) {
			counterWalking = 0;
		}

		counterRoad++;
		if (counterRoad >= movementLenght)
		{
			direction = generateRandom(8);
			counterRoad = 0;
		}
	}
}


void enemy::attackRight(int postac) {
	if (postac == 0) {
		if (!animating && !animating2 && !animating3 && !animating)direction = generateRandom(8);
		if (direction == 1 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(115, 263, 107, 95));
			rect.setSize(sf::Vector2f(107, 95));
		}

		if (animating) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(29, 264, 79, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(115, 263, 107, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(230, 264, 77, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(315, 264, 66, 94));
					animating = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}

		if (direction == 2 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating2 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(642, 265, 109, 93));
			rect.setSize(sf::Vector2f(109, 93));
		}

		if (animating2) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(563, 264, 71, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(642, 265, 109, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(759, 264, 71, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(838, 264, 65, 94));
					animating2 = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}

		if (direction == 5 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating3 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(162, 23, 101, 86));
			rect.setSize(sf::Vector2f(101, 86));
		}

		if (animating3) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(4, 10, 83, 99));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(95, 17, 59, 92));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(162, 23, 101, 86));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(271, 23, 55, 86));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(334, 10, 82, 101));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
					animating3 = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}

		if (direction == 6 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating4 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(761, 28, 113, 99));
			rect.setSize(sf::Vector2f(113, 99));
		}

		if (animating4) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(511, 36, 67, 91));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(586, 21, 73, 106));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(667, 6, 86, 121));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(761, 28, 113, 99));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(882, 39, 114, 88));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(1004, 35, 94, 92));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
					animating4 = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}
	}

	if (postac == 1) {
		if (!animating && !animating2 && !animating3 && !animating)direction = generateRandom(8);
		if (direction == 1 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(176, 256, 108, 94));

		}

		if (animating) {
			rect.setSize(sf::Vector2f(108, 94));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(4, 256, 72, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(84, 256, 84, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(176, 256, 108, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(292, 256, 84, 94));
					animating = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}

		if (direction == 2 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating2 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(624, 257, 128, 92));
		}

		if (animating2) {
			rect.setSize(sf::Vector2f(128, 92));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(464, 256, 72, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(544, 257, 75, 92));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(624, 257, 128, 92));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(951, 256, 75, 94));
					animating2 = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}

		if (direction == 5 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating3 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(156, 368, 124, 93));
		}

		if (animating3) {
			rect.setSize(sf::Vector2f(124, 93));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(25, 368, 51, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(83, 367, 65, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(156, 368, 124, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(288, 368, 50, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(951, 256, 75, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(951, 256, 75, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(951, 256, 75, 94));
					animating3 = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}

		if (direction == 6 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating4 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(600, 366, 128, 111));
		}

		if (animating4) {
			rect.setSize(sf::Vector2f(128, 111));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(365, 384, 84, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(457, 377, 135, 100));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(600, 366, 128, 111));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(736, 366, 102, 111));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(846, 383, 84, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(951, 256, 75, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(951, 256, 75, 94));
					animating4 = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}
	}
}
	

void enemy::attackLeft(int postac) {
	if (postac == 0) {
		if (!animating && !animating2 && !animating3 && !animating)direction = generateRandom(8);
		if (direction == 1 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(216, 263, 106, 95));
			rect.setSize(sf::Vector2f(106, 95));
		}

		if (animating) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(56, 264, 66, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(130, 264, 77, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(216, 263, 106, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(330, 264, 77, 94));
					animating = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}

		if (direction == 2 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating2 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(755, 265, 109, 93));
			rect.setSize(sf::Vector2f(109, 93));
		}

		if (animating2) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(676, 264, 71, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(755, 265, 109, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(676, 264, 71, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(951, 264, 65, 94));
					animating2 = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}

		if (direction == 5 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating3 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(233, 23, 102, 86));
			rect.setSize(sf::Vector2f(102, 86));
		}

		if (animating3) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(5, 17, 66, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(95, 17, 59, 92));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(162, 23, 101, 86));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(271, 23, 55, 86));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(334, 10, 82, 101));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(425, 17, 66, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(5, 17, 66, 94));
					animating3 = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}

		if (direction == 6 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating4 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(794, 28, 113, 99));
			rect.setSize(sf::Vector2f(113, 99));
		}

		if (animating4) {
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(5, 17, 66, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(586, 21, 73, 106));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(667, 6, 86, 121));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(761, 28, 113, 99));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(882, 39, 114, 88));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(1004, 35, 94, 92));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(5, 17, 66, 94));
					animating4 = false;
					rect.setSize(sf::Vector2f(63, 95));
				}
			}
		}
	}

	if (postac == 1) {
		if (!animating && !animating2 && !animating3 && !animating)direction = generateRandom(8);
		if (direction == 1 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(305, 256, 128, 93));
		}

		if (animating) {
			rect.setSize(sf::Vector2f(128, 93));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(524, 255, 72, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(441, 256, 75, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(305, 256, 128, 93));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(37, 256, 73, 94));
					animating = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}

		if (direction == 2 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating2 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(776, 255, 108, 95));
		}

		if (animating2) {
			rect.setSize(sf::Vector2f(108, 95));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(984, 255, 72, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(891, 255, 85, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(776, 255, 108, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(603, 255, 73, 95));
					animating2 = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}

		if (direction == 5 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating3 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(780, 367, 124, 94));
		}

		if (animating3) {
			rect.setSize(sf::Vector2f(124, 94));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(985, 367, 51, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(912, 367, 65, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(780, 367, 124, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(722, 367, 50, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(603, 255, 73, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(603, 255, 73, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(603, 255, 73, 95));
					animating3 = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}

		if (direction == 6 && !animating && !animating2 && !animating3 && !animating4)
		{
			direction = generateRandom(8);
			attack = true;
			animating4 = true;
			animacja.restart();
			counterAttack = 0;
			sprite.setTextureRect(sf::IntRect(332, 366, 128, 111));
		}

		if (animating4) {
			rect.setSize(sf::Vector2f(128, 111));
			if (animacja.getElapsedTime().asMilliseconds() >= 400) {

				if (counterAttack == 0) {
					sprite.setTextureRect(sf::IntRect(611, 383, 84, 94));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 1) {
					sprite.setTextureRect(sf::IntRect(468, 376, 135, 101));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 2) {
					sprite.setTextureRect(sf::IntRect(332, 366, 128, 111));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 3) {
					sprite.setTextureRect(sf::IntRect(221, 377, 103, 100));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 4) {
					sprite.setTextureRect(sf::IntRect(130, 377, 85, 100));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 5) {
					sprite.setTextureRect(sf::IntRect(603, 255, 73, 95));
					counterAttack++;
					animacja.restart();
				}

				if (counterAttack == 6) {
					sprite.setTextureRect(sf::IntRect(603, 255, 73, 95));
					animating4 = false;
					rect.setSize(sf::Vector2f(70, 100));
				}
			}
		}
	}
}