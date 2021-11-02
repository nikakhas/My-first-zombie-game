#include "Global.h"
#include "GameInit.h"
#include "Draw.h"
#include "Input.h"
#include "Logic.h"
#include "MainHero.h"

int main() {
 	
	sf::Event event;
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Game", sf::Style::Fullscreen);
	window.setFramerateLimit(80);
	// HERO CTOR (texture, intrect, posX, posY, accessible, speed, hp, attack, defense, alive, name, coins);
	MainHero hero(GameInit::GetTexture(enumTextures::playerTexture), sf::IntRect(0, 32, 32, 32),
		400, 1000, false, 10, 100, 10, 10, true, "!", 0);

	GameInit::InitTextures();
	GameInit::InitMap(window);
	GameInit::InitChars(window);

	hero.getSprite().setTexture(GameInit::GetTexture(enumTextures::playerTexture));
	hero.getSprite().setTextureRect(sf::IntRect(0, 32, 32, 32));
	hero.setOrigin(hero.getWidth() / 2, hero.getHeight());
	hero.setScale(4.5, 4.5);
	hero.setPosition(120, window.getSize().y - 150);
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	while (window.isOpen()) {

		Input::movePerson(event, window, hero, clock);

		Logic::GameLogic(hero, window);

		Draw::DrawLevel(window, hero);

	}

}