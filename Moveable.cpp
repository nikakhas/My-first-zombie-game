#include "Moveable.h"

void Moveable::moveMoveable(bool direction, int steps) {
	this->direction = direction;
	this->steps = steps;
	this->move = steps;
}

void Moveable::moveableUpdate() {
	if (this->clock.getElapsedTime().asSeconds() < 0.5)
		return;

	if (direction) {
		if (this->steps > 0) {
			this->setPosition(this->getPosition().x + this->getSpeed(), this->getPosition().y);
			this->steps--;
			if (!this->steps)
				this->steps = -move;
		}
		else if (this->steps < 0) {
			this->setPosition(this->getPosition().x - this->getSpeed(), this->getPosition().y);
			this->steps++;
			if (!this->steps)
				this->steps = move;
		}
	}
	else {
		if (this->steps > 0) {
			this->setPosition(this->getPosition().x, this->getPosition().y + this->getSpeed());
			this->steps--;
			if (!this->steps)
				this->steps = -move;
		}
		else if (this->steps < 0) {
			this->setPosition(this->getPosition().x, this->getPosition().y - this->getSpeed());
			this->steps++;
			if (!this->steps)
				this->steps = move;
		}
	}
	clock.restart();
}

void Moveable::setSpeed(float speed)
{
	this->speed = speed;
}

float Moveable::getSpeed()
{
	return this->speed;
}
