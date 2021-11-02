#pragma once
#include "MainHero.h"
#include "GameInit.h"

static class Input {
public:
	static void movePerson(sf::Event& event, sf::RenderWindow& window, MainHero& hero, sf::Clock& clock);
};

