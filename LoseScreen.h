#pragma once
#include <memory>
#include "Game.hpp"

class LoseScreen : public State
{
public:
	LoseScreen(std::shared_ptr<GameBase> data);

	void handleInput() override;
	void update() override;
	void draw() override;

private:
	std::shared_ptr<GameBase> data_;
};

