#include "WinScreen.h"
#include <SFML/Window/Event.hpp>
#include "StartScreen.h"

WinScreen::WinScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void WinScreen::handleInput()
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
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && option ==1)
		{
			data_->window.close();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && option==0)
		{
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<StartScreen>(data_), true);
		}
	}
}

void WinScreen::update() {

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && clock.getElapsedTime().asMilliseconds() > 400) {
		++option;
		if (option == 2)option = 0;
		sbackground.setTextureRect(sf::IntRect(0, 113 + (option * 375), 663, 223));
		clock.restart();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && clock.getElapsedTime().asMilliseconds() > 400) {
		--option;
		if (option == -1)option = 1;
		sbackground.setTextureRect(sf::IntRect(0, 113 + (option * 375), 663, 223));
		clock.restart();
	}

	else sbackground.setTextureRect(sf::IntRect(0, 113 + (option * 375), 663, 223));

}

void WinScreen::draw()
{

	tbackground.loadFromFile("../External/Graphics/gameover.jpg");
	sbackground.setTexture(tbackground);

	data_->window.draw(sbackground);
	data_->window.display();
}