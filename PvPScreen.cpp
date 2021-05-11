#include "PvPScreen.h"
#include <SFML/Window/Event.hpp>
#include "GameScreenVsP.h"
#include "StartScreen.h"

PvPScreen::PvPScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void PvPScreen::handleInput()
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

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
			data_->maschine.postacc = postac;
			data_->maschine.postacc2 = postac2;
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<GameScreenVsP>(data_), true);
		}
	}
}

void PvPScreen::update() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && clock.getElapsedTime().asMilliseconds() > 400) {
		++postac;
		if (postac == 2)postac = 0;
		sbackground.setTextureRect(sf::IntRect(0, 0 + (postac * 249), 601, 249));
		clock.restart();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && clock.getElapsedTime().asMilliseconds() > 400) {
		--postac;
		if (postac == -1)postac = 1;
		sbackground.setTextureRect(sf::IntRect(0, 0 + (postac * 249), 601, 249));
		clock.restart();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && clock2.getElapsedTime().asMilliseconds() > 400) {
		++postac2;
		if (postac2 == 2)postac2 = 0;
		sbackground2.setTextureRect(sf::IntRect(0, 0 + (postac2 * 249), 601, 249));
		clock2.restart();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && clock2.getElapsedTime().asMilliseconds() > 400) {
		--postac2;
		if (postac2== -1)postac2 = 1;
		sbackground2.setTextureRect(sf::IntRect(0, 0 + (postac2 * 249), 601, 249));
		clock2.restart();
	}

}

void PvPScreen::draw()
{
	tbackground.loadFromFile("../External/Graphics/PvP1.jpg");
	tbackground2.loadFromFile("../External/Graphics/PvP2.jpg");
	sbackground.setTexture(tbackground);
	sbackground2.setTexture(tbackground2);
	sbackground2.setPosition(sf::Vector2f(300, 0));

	sbackground.setScale(sf::Vector2f(0.5, 1));
	sbackground2.setScale(sf::Vector2f(0.5, 1));

	data_->window.draw(sbackground);
	data_->window.draw(sbackground2);
	data_->window.display();
}