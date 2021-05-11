#pragma once
#include <memory>
#include "Game.hpp"

class PvEScreen : public State
{
public:
	PvEScreen(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

	int postac = 0;

private:
	std::shared_ptr<GameBase> data_;
	sf::Sprite sbackground;
	sf::Texture tbackground;
	sf::Clock clock;
	
	
};

