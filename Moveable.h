#pragma once
#include "Object.h"

class Moveable : public Object
{
	sf::Clock clock;
	int move = 0;
	int steps = 0;
	bool direction = false;
	float speed;
public: 
	Moveable(sf::Texture texture, sf::IntRect intrect, float posX, float posY, bool accessable, float speed)
		: Object(texture, intrect, posX, posY, accessable) {
		this->speed = speed;
		this->clock.getElapsedTime().asSeconds();
	};

	void moveMoveable(bool direction, int steps);
	void moveableUpdate();
	void setSpeed(float speed);
	float getSpeed();
};