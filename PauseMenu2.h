#pragma once
#include <memory>
#include "Game.hpp"

class PauseMenu2 : public State
{
public:
	PauseMenu2(std::shared_ptr<GameBase> data);

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

