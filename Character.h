#pragma once
#include "Moveable.h"

class Character : public Moveable {
	int hp;
	int attack;
	int defense;
	bool alive;
public:
	Character(sf::Texture texture, sf::IntRect intrect, float posX, float posY, bool accessable, float speed,
		int hp, int attack, int defense, bool alive) 
		: Moveable(texture, intrect, posX, posY, accessable, speed) {
		this->hp = hp;
		this->attack = attack;
		this->defense = defense;
		this->alive = alive;
	}
	void setCharacterParams(float speed, int hp, int attack, int defense, bool alive);
	void setHp(int hp);
	int getHp();
	void setAttack(int attack);
	int getAttack();
	void setDefense(int defense);
	int getDefense();
	void setAlive(bool alive);
	bool getAlive();
};