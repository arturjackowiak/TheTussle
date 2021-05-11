#include <SFML/Window/Event.hpp>
#include "GameScreenVsP.h"
#include "StartScreen.h"
#include "WinScreen.h"
#include "LoseScreen.h"
#include "PvPScreen.h"
#include "PauseMenu.h"

GameScreenVsP::GameScreenVsP(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void GameScreenVsP::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<PauseMenu>(data_), true);
		}

		if (wins==2) {
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<WinScreen>(data_), true);
		}
		if (loses==2) {
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<WinScreen>(data_), true);
		}
	}
}

void GameScreenVsP::update()
{
	sf::Time elapsed1 = clock1.getElapsedTime();
	sf::Time elapsed2 = clock2.getElapsedTime();

	//DMG
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::U) || sf::Keyboard::isKeyPressed(sf::Keyboard::I) || sf::Keyboard::isKeyPressed(sf::Keyboard::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::K)) && Player.rect.getGlobalBounds().intersects(Enemy.rect.getGlobalBounds()) && elapsed1.asMilliseconds() >= 400) {
		Enemy.hp -= 10;
		if (Enemy.hp <= 0) Enemy.alive = false;
		clock1.restart();
	}
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) && Enemy.rect.getGlobalBounds().intersects(Player.rect.getGlobalBounds()) && elapsed2.asMilliseconds() >= 400) {
		Player.hp -= 10;
		if (Player.hp <= 0) Player.alive = false;
		clock2.restart();
	}

	Player.update();
	Enemy.update();
}

void GameScreenVsP::draw()
{
	tbackground.loadFromFile("../External/Graphics/street.png");
	sbackground.setTexture(tbackground);

	hpTexture.loadFromFile("../External/Graphics/hp.png");
	characterTexture.loadFromFile("../External/Graphics/Character3.png");
	characterTextureB.loadFromFile("../External/Graphics/Character1.png");
	characterTexture2.loadFromFile("../External/Graphics/Character3b.png");
	characterTextureB2.loadFromFile("../External/Graphics/Character1b.png");

	hpSpritePlayer.setTexture(hpTexture);
	hpSpriteEnemy.setTexture(hpTexture);
	roundTexture.loadFromFile("../External/Graphics/rounds.png");
	roundSpriteEnemy.setTexture(roundTexture);
	roundSpritePlayer.setTexture(roundTexture);

	if (Player.rect.getPosition().x < Enemy.rect.getPosition().x) {
		if (data_->maschine.postacc == 0) {
			Player.sprite.setTexture(characterTexture);
			Player.updateMovement(data_->maschine.postacc);
		}
		else if (data_->maschine.postacc == 1) {
			Player.sprite.setTexture(characterTextureB);
			Player.updateMovement(data_->maschine.postacc);
		}

		if (data_->maschine.postacc2 == 0) {
			Enemy.sprite.setTexture(characterTexture2);
			Enemy.updateMovement(data_->maschine.postacc2);
		}
		else if (data_->maschine.postacc2 == 1) {
			Enemy.sprite.setTexture(characterTextureB2);
			Enemy.updateMovement(data_->maschine.postacc2);
		}
	}

	else{
		if (data_->maschine.postacc == 0) {
			Player.sprite.setTexture(characterTexture2);
			Player.updateMovementL(data_->maschine.postacc);
		}
		else if (data_->maschine.postacc == 1) {
			Player.sprite.setTexture(characterTextureB2);
			Player.updateMovementL(data_->maschine.postacc);
		}

		if (data_->maschine.postacc2 == 0) {
			Enemy.sprite.setTexture(characterTexture);
			Enemy.updateMovementR(data_->maschine.postacc2);
		}
		else if (data_->maschine.postacc2 == 1) {
			Enemy.sprite.setTexture(characterTextureB);
			Enemy.updateMovementR(data_->maschine.postacc2);
		}
	}
	
	if (Player.hp >= -10) {
		if (Player.hp == 100)
			hpSpritePlayer.setTextureRect(sf::IntRect(24, 39, 522, 235));

		if (Player.hp == 90)
			hpSpritePlayer.setTextureRect(sf::IntRect(553, 39, 522, 235));

		if (Player.hp == 80)
			hpSpritePlayer.setTextureRect(sf::IntRect(24, 294, 522, 235));

		if (Player.hp == 70)
			hpSpritePlayer.setTextureRect(sf::IntRect(553, 294, 522, 235));

		if (Player.hp == 60)
			hpSpritePlayer.setTextureRect(sf::IntRect(24, 555, 522, 235));

		if (Player.hp == 50)
			hpSpritePlayer.setTextureRect(sf::IntRect(553, 555, 522, 235));

		if (Player.hp == 40)
			hpSpritePlayer.setTextureRect(sf::IntRect(24, 828, 522, 235));

		if (Player.hp == 30)
			hpSpritePlayer.setTextureRect(sf::IntRect(553, 828, 522, 235));

		if (Player.hp == 20)
			hpSpritePlayer.setTextureRect(sf::IntRect(24, 1096, 522, 235));

		if (Player.hp == 10)
			hpSpritePlayer.setTextureRect(sf::IntRect(553, 1096, 522, 235));

		if (Player.hp <= 0) {
			loses++;
			Enemy.hp = 100;
			Player.hp = 100;
			Player.rect.setPosition(0, 125);
			Enemy.rect.setPosition(500, 125);
		}
	}

	if (Enemy.hp >= -10) {
		if (Enemy.hp == 100)
			hpSpriteEnemy.setTextureRect(sf::IntRect(24, 39, 522, 235));

		if (Enemy.hp == 90)
			hpSpriteEnemy.setTextureRect(sf::IntRect(553, 39, 522, 235));

		if (Enemy.hp == 80)
			hpSpriteEnemy.setTextureRect(sf::IntRect(24, 294, 522, 235));

		if (Enemy.hp == 70)
			hpSpriteEnemy.setTextureRect(sf::IntRect(553, 294, 522, 235));

		if (Enemy.hp == 60)
			hpSpriteEnemy.setTextureRect(sf::IntRect(24, 555, 522, 235));

		if (Enemy.hp == 50)
			hpSpriteEnemy.setTextureRect(sf::IntRect(553, 555, 522, 235));

		if (Enemy.hp == 40)
			hpSpriteEnemy.setTextureRect(sf::IntRect(24, 828, 522, 235));

		if (Enemy.hp == 30)
			hpSpriteEnemy.setTextureRect(sf::IntRect(553, 828, 522, 235));

		if (Enemy.hp == 20)
			hpSpriteEnemy.setTextureRect(sf::IntRect(24, 1096, 522, 235));

		if (Enemy.hp == 10)
			hpSpriteEnemy.setTextureRect(sf::IntRect(553, 1096, 522, 235));

		if (Enemy.hp <= 0) {
			wins++;
			Enemy.hp = 100;
			Player.hp = 100;
			Player.rect.setPosition(0, 125);
			Enemy.rect.setPosition(500, 125);
		}
	}

	hpSpritePlayer.setScale(sf::Vector2f(0.4, 0.2));
	hpSpriteEnemy.setScale(sf::Vector2f(0.4, 0.2));
	hpSpriteEnemy.setPosition(390, 0);

	roundSpritePlayer.setScale(sf::Vector2f(0.3, 0.1));
	roundSpriteEnemy.setScale(sf::Vector2f(0.3, 0.1));
	roundSpriteEnemy.setPosition(390, 48);
	roundSpritePlayer.setPosition(175, 48);

	if (wins == 0 && loses == 0) {
		roundSpritePlayer.setTextureRect(sf::IntRect(0, 20, 113, 114));
		roundSpriteEnemy.setTextureRect(sf::IntRect(0, 20, 113, 114));
	}

	if (wins == 1 && loses == 0) {
		roundSpritePlayer.setTextureRect(sf::IntRect(114, 20, 113, 114));
		roundSpriteEnemy.setTextureRect(sf::IntRect(0, 20, 113, 114));
	}

	if (wins == 0 && loses == 1) {
		roundSpritePlayer.setTextureRect(sf::IntRect(0, 20, 113, 114));
		roundSpriteEnemy.setTextureRect(sf::IntRect(228, 20, 113, 114));
	}

	if (wins == 1 && loses == 1) {
		roundSpritePlayer.setTextureRect(sf::IntRect(114, 20, 113, 114));
		roundSpriteEnemy.setTextureRect(sf::IntRect(228, 20, 113, 114));
	}




	data_->window.draw(sbackground);
	data_->window.draw(Player.sprite);
	data_->window.draw(Enemy.sprite);
	data_->window.draw(hpSpritePlayer);
	data_->window.draw(hpSpriteEnemy);
	data_->window.draw(roundSpriteEnemy);
	data_->window.draw(roundSpritePlayer);
	data_->window.display();
	
}