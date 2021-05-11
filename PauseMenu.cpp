#include "PauseMenu.h"
#include <SFML/Window/Event.hpp>
#include "StartScreen.h"
#include "GameScreenVsP.h"


PauseMenu::PauseMenu(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void PauseMenu::handleInput()
{
	sf::Event event{};
	while (data_->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data_->window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			data_->window.close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<GameScreenVsP>(data_), true);
		}
	}
}

void PauseMenu::update() {

}

void PauseMenu::draw()
{

	tbackground.loadFromFile("../External/Graphics/pausemenu.jpg");
	sbackground.setTexture(tbackground);

	data_->window.draw(sbackground);
	data_->window.display();
}