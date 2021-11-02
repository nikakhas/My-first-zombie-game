#include "MainHero.h"

void MainHero::setCoins(int coins)
{
	this->coins = coins;
}

int MainHero::getCoins()
{
	return this->coins;
}

int MainHero::getJump()
{
	return this->jump;
}

int MainHero::getAttackCount()
{
	return this->attack;
}

void MainHero::setName(string name) {
	this->name = name;
}

string MainHero::getName() {
	return this->name;
}

void MainHero::moveHero(sf::Event& event, sf::RenderWindow& window, int& time) {
	switch (event.key.code) {

		// GO RIGHT
	case sf::Keyboard::Right:
		if (this->getPosition().x + this->getSpeed() < window.getSize().x - this->getWidth() / 2 - 10) {
			this->setPosition(this->getPosition().x + this->getSpeed(), this->getPosition().y);
			this->setScale(4.5, 4.5);
			this->heroRun(time);
		}
		break;

		// GO LEFT
	case sf::Keyboard::Left:
		if (this->getPosition().x - this->getSpeed() > this->getWidth() + 4) {
			this->setPosition(this->getPosition().x - this->getSpeed(), this->getPosition().y);
			this->setScale(-4.5, 4.5);
			this->heroRun(time);
		}
		break;

		// GO UP
	case::sf::Keyboard::Up:
		if (this->getPosition().y > GameInit::GetGrassGradient().getPosition().y + 50) {
			this->setPosition(this->getPosition().x, this->getPosition().y - this->getSpeed() / 2);
			this->heroRun(time);
		}
		break;

		// GO DOWN
	case::sf::Keyboard::Down:
		if (this->getPosition().y < window.getSize().y - 140) {
			this->setPosition(this->getPosition().x, this->getPosition().y + this->getSpeed() / 2);
			this->heroRun(time);
		}
		break;
		
		// ATTACK
	case sf::Keyboard::K:
		this->attackMode = rand() % 3;
		this->attack = 6;
		break;

		// JUMP
	case sf::Keyboard::Space:
		if (!this->jump) 
			this->jump = 10;
		break;
		
		// CHEAT
	case sf::Keyboard::Z:
		while (GameInit::GetEnemyVector().size())
			GameInit::GetEnemyVector().pop_back();
	}
}

void MainHero::heroUpdate(sf::RenderWindow& window) {
	float time = this->clock.getElapsedTime().asSeconds();

	// ALIVE LOGIC
	if (!this->getAlive()) {
		sf::Font font;
		font.loadFromFile("Fonts/Antonio-Bold.ttf");
		string victoryStr = this->getName() + " lose!";
		sf::Text text(victoryStr, font);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		text.setScale(3, 3);
		text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
		sf::Clock clock;
		while (clock.getElapsedTime().asSeconds() < 5) {
			window.draw(text);
			window.display();
		}
		window.close();
	}

	if (this->getHp() <= 0) {
		this->setAlive(false);
	}

	// ATTACK LOGIC
	if (this->attack > 0 && time > 0.05) {
		this->clock.restart();
		this->heroAttack();
	}

	// JUMP LOGIC
	if (this->jump && time > 0.02) {
		this->getSprite().setTextureRect(sf::IntRect(128, 160, 32, 32));
		if (this->jump > 0) {
			this->setPosition(this->getPosition().x, this->getPosition().y - 20);
			this->jump--;
			if (!this->jump)
				this->jump = -10;
		}
		else {
			this->setPosition(this->getPosition().x, this->getPosition().y + 20);
			this->jump++;
			if (!this->jump) 
				this->getSprite().setTextureRect(sf::IntRect(0, 32, 32, 32));
		}
		this->clock.restart();
	}

	// WAIT LOGIC
	if (time >= 10) {
		this->getSprite().setTextureRect(sf::IntRect(32 * (((int)time - 10) % 13), 0, 32, 32));
		if (time > 10000)
			this->clock.getElapsedTime().asSeconds();
	}
}

void MainHero::heroAttack() {
	switch (this->attackMode) {
	case HERO_ATTACK_MODE::FirstAttack:
		this->getSprite().setTextureRect(sf::IntRect(32 * (7 - this->attack), 64, 32, 32));
		break;
	case HERO_ATTACK_MODE::SecondAttack:
		this->getSprite().setTextureRect(sf::IntRect(32 * (7 - this->attack), 96, 32, 32));
		break;
	case HERO_ATTACK_MODE::ThirdAttack:
		this->getSprite().setTextureRect(sf::IntRect(32 * (7 - this->attack), 128, 32, 32));
		break;
	}
	this->attack--;
}

void MainHero::heroRun(int& time) {
	this->clock.restart();
	switch (time % 3) {
	case 0:
		this->getSprite().setTextureRect(sf::IntRect(0, 32, 32, 32));
		break;
	case 1:
		this->getSprite().setTextureRect(sf::IntRect(96, 32, 32, 32));
		break;
	case 2:
		this->getSprite().setTextureRect(sf::IntRect(64, 32, 32, 32));
		break;
	}
}