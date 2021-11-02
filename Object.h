#pragma once
#include "Global.h"

class Object {
	sf::Sprite sprite;
	static int objectsCount;
	float posX, posY;
	float width, height;
	float scaleX, scaleY;
	float originX, originY;
	bool accessable;

public:
	Object() = default;

	Object(sf::Texture texture, sf::IntRect intrect, float posX, float posY, bool accessable);

	~Object() { this->objectsCount--; };

	//virtual void move() = 0;

	void setPosition(float x, float y);
	void setScale(float x, float y);
	void setOrigin(float x, float y);
	void setTexture(sf::Texture texture, sf::IntRect rect);
	void setAccessable(bool access);

	sf::Vector2f getPosition();
	float getWidth();
	float getHeight();
	sf::Vector2f getScale();
	sf::Vector2f getOrigin();
	sf::Sprite& getSprite();
	bool getAccessable();
	static int getObjectsCount();
	void drawSprite(sf::RenderWindow& window);
};

