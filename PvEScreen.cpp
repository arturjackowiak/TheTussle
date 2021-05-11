#include "PvEScreen.h"
#include <SFML/Window/Event.hpp>
#include "GameScreenVsE.h"
#include "StartScreen.h"

PvEScreen::PvEScreen(std::shared_ptr<GameBase> data) : data_(std::move(data))
{
}

void PvEScreen::handleInput()
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
			data_->maschine.removeState();
			data_->maschine.addState(std::make_unique<GameScreenVsE>(data_), true);
		}
	}
}

void PvEScreen::update() {

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
}

void PvEScreen::draw()
{
	tbackground.loadFromFile("../External/Graphics/PvE.jpg");
	sbackground.setTexture(tbackground);



	data_->window.draw(sbackground);
	data_->window.display();
}