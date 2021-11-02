#pragma once
#include "Character.h"
#include "GameInit.h"

enum HERO_ATTACK_MODE {
	FirstAttack,
	SecondAttack,
	ThirdAttack
};

class MainHero : public Character {
	sf::Clock clock;
	int attackMode;
	int jump = 0;
	int attack = 0;
	int run = 0;
	string name;
	int coins;
public:
	MainHero() = default;
	MainHero(sf::Texture texture, sf::IntRect intrect, float posX, float posY, bool accessable, float speed,
		int hp, int attack, int defense, bool alive, string name, int coins)
		: Character(texture, intrect, posX, posY, accessable, speed, hp, attack, defense, alive) {
		this->name = name;
		this->coins = coins;
		this->clock.getElapsedTime().asSeconds();
	}
	void setName(string name);
	string getName();
	void setCoins(int coins);
	int getCoins();
	int getJump();
	int getAttackCount();

	void moveHero(sf::Event& event, sf::RenderWindow& window, int& time);
	void heroRun(int& time);
	void heroAttack();
	void heroUpdate(sf::RenderWindow& window);
};