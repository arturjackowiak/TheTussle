#include "LoseScreen.h"
#include <SFML/Window/Event.hpp>
#include "StartScreen.h"

LoseScreen::LoseScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void LoseScreen::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}
	}
}

void LoseScreen::update() {}

void LoseScreen::draw()
{
	data_->window.display();
}