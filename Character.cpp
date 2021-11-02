#include "Character.h"

void Character::setCharacterParams(float speed, int hp, int attack, int defense, bool alive) {
	this->setSpeed(speed);
	this->hp = hp;
	this->attack = attack;
	this->defense = defense;
	this->alive = alive;
}

void Character::setHp(int hp) { this->hp = hp; }

int Character::getHp() { return this->hp; }

void Character::setAttack(int attack) { this->attack = attack; }

int Character::getAttack() { return this->attack; }

void Character::setDefense(int defense) { this->defense = defense; }

int Character::getDefense() { return this->defense; }

void Character::setAlive(bool alive) { this->alive = alive; }

bool Character::getAlive() { return this->alive; }