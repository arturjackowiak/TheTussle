#pragma once
#include <memory>
#include "Game.hpp"

class PvPScreen : public State
{
public:
	PvPScreen(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;
	int postac = 0;
	int postac2 = 0;

private:
	std::shared_ptr<GameBase> data_;
	
	sf::Sprite sbackground;
	sf::Sprite sbackground2;
	sf::Texture tbackground;
	sf::Texture tbackground2;
	sf::Clock clock;
	sf::Clock clock2;
	
};

