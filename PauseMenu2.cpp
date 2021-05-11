#include "PauseMenu2.h"
#include <SFML/Window/Event.hpp>
#include "StartScreen.h"
#include "GameScreenVsE.h"


PauseMenu2::PauseMenu2(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void PauseMenu2::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			data_->window.close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<GameScreenVsE>(data_), true);
		}
	}
}

void PauseMenu2::update() {

}

void PauseMenu2::draw()
{

	tbackground.loadFromFile("../External/Graphics/pausemenu2.jpg");
	sbackground.setTexture(tbackground);

	data_->window.draw(sbackground);
	data_->window.display();
}