#include "Object.h"

int Object::objectsCount;

Object::Object(sf::Texture texture, sf::IntRect intrect, float posX, float posY, bool accessable) {
	this->posX = posX;
	this->posY = posY;
	this->accessable = accessable;
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(intrect);
	this->width = sprite.getTextureRect().width;
	this->height = sprite.getTextureRect().height;
	this->scaleX = sprite.getScale().x;
	this->scaleY = sprite.getScale().y;
	this->originX = sprite.getOrigin().x;
	this->originY = sprite.getOrigin().y;
	this->sprite.setPosition(this->posX, this->posY);
	
	this->objectsCount++;
}

void Object::setPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;
	this->sprite.setPosition(this->posX, this->posY);
}

void Object::setScale(float x, float y)
{
	this->scaleX = x;
	this->scaleY = y;
	this->sprite.setScale(this->scaleX, this->scaleY);
}

void Object::setOrigin(float x, float y)
{
	this->originX = x;
	this->originY = y;
	this->sprite.setOrigin(this->originX, this->originY);
}

void Object::setTexture(sf::Texture texture, sf::IntRect rect) {
	this->getSprite().setTexture(texture);
	this->getSprite().setTextureRect(rect);
}

void Object::setAccessable(bool access)
{
	this->accessable = access;
}


sf::Vector2f Object::getPosition() {
	return { this->posX, this->posY };
}
float Object::getWidth() {
	return this->width;
}
float Object::getHeight() {
	return this->height;
}
sf::Vector2f Object::getScale() {
	return { this->scaleX, this->scaleY };
}
sf::Vector2f Object::getOrigin() {
	return { this->originX, this->originY };
}
sf::Sprite& Object::getSprite() {
	return this->sprite;
}
bool Object::getAccessable() {
	return this->accessable;
}
int Object::getObjectsCount() {
	return Object::objectsCount;
}
void Object::drawSprite(sf::RenderWindow& window) {
	window.draw(this->sprite);
}
