#pragma once
#include "MainHero.h"
#include "GameInit.h"

static class Logic {
	static sf::Clock clockEnemyMove;
	static sf::Clock clockEnemyDeath;
	static sf::Clock clockEnemyAttack;
	static sf::Clock clockHeroAttack;
public:
	static void CharsMoveLogic(MainHero& hero, sf::RenderWindow& window);
	static void CharsAttackLogic(MainHero& hero);
	static void HeroAttackLogic(MainHero& hero);
	static void MoveableLogic();
	static void GameLogic(MainHero& hero, sf::RenderWindow& window);
};