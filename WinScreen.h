#pragma once
#include <memory>
#include "Game.hpp"

class WinScreen : public State
{
public:
	WinScreen(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

private:
	std::shared_ptr<GameBase> data_;
	sf::Sprite sbackground;
	sf::Texture tbackground;
	sf::Clock clock;
	int option = 0;
};

