#include "Input.h"

void Input::movePerson(sf::Event& event, sf::RenderWindow& window, MainHero& hero, sf::Clock& clock) {

	int time = clock.getElapsedTime().asMilliseconds();
	time /= 100;

	while (window.pollEvent(event)) {

		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
			window.close();

		else if (event.type == sf::Event::KeyPressed)
			hero.moveHero(event, window, time);

		else if (!hero.getJump()) {
			hero.getSprite().setTexture(GameInit::GetTexture(enumTextures::playerTexture));
			hero.getSprite().setTextureRect(sf::IntRect(0, 32, 32, 32));
		}

	}

}