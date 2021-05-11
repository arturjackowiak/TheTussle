#pragma once
#include <memory>
#include "Game.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>
#include "projectile.h"
#include "enemy.h"
#include "player.h"
#include "playerb.h"

class GameScreenVsP : public State
{
public:
	GameScreenVsP(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

private:
	std::shared_ptr<GameBase> data_;

	bool win{ false };
	bool lose{ false };

	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;

	sf::Sprite sbackground;
	sf::Sprite characterSprite;
	sf::Music music;
	sf::Sprite hpSpritePlayer;
	sf::Sprite hpSpriteEnemy;
	sf::Sprite roundSpriteEnemy;
	sf::Sprite roundSpritePlayer;
	sf::Texture roundTexture;
	sf::Texture characterTexture;
	sf::Texture characterTextureB;
	sf::Texture characterTexture2;
	sf::Texture characterTextureB2;
	sf::Texture hpTexture;
	sf::Texture tbackground;
	
	int wins = 0;
	int loses = 0;

	// Klasa postaci
	player Player;
	playerb Enemy;

	// Wektor pociskow
	std::vector<projectile>::const_iterator iter;
	std::vector<projectile> projectileArray;

	// Klasa pocisku
	projectile projectile1;

};

