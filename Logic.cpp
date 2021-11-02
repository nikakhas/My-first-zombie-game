#include "Logic.h"
sf::Clock Logic::clockEnemyMove;
sf::Clock Logic::clockEnemyAttack;
sf::Clock Logic::clockEnemyDeath;
sf::Clock Logic::clockHeroAttack;

void Logic::CharsMoveLogic(MainHero& hero, sf::RenderWindow& window) {

	// ENEMY DEATH LOGIC
	for (int i = 0; i < GameInit::GetEnemyVector().size(); i++) {
		Character& thisEnemy = GameInit::GetEnemyVector()[i];
		if (!thisEnemy.getAlive()) {
			GameInit::GetEnemyVector().erase(GameInit::GetEnemyVector().begin() + i);
			hero.setCoins(hero.getCoins() + 10);
		}
	}

	// VICTORY LOGIC
	if (!GameInit::GetEnemyVector().size()) {
		if (hero.getPosition().x > GameInit::GetDoorVector()[0].getPosition().x - 10 &&
			hero.getPosition().x < GameInit::GetDoorVector()[0].getPosition().x + GameInit::GetDoorVector()[0].getWidth() + 10)
			if (hero.getPosition().y < GameInit::GetGrassGradient().getPosition().y - GameInit::GetGrassGradient().getHeight() + 70) {
				sf::Font font;
				font.loadFromFile("Fonts/Antonio-Bold.ttf");
				string victoryStr = "Congrats, " + hero.getName();
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
		GameInit::GetDoorVector()[0].getSprite().setTextureRect(sf::IntRect(647, 287, 72, 70));
		GameInit::GetDoorVector()[1].getSprite().setTextureRect(sf::IntRect(647, 215, 72, 70));
		return;
	}


	if (Logic::clockEnemyMove.getElapsedTime().asSeconds() < 0.2)
		return;

	if (hero.getPosition().y < GameInit::GetGrassGradient().getPosition().y)
		return;

	// ENEMY MOVE LOGIC
	int randEnemy = rand() % GameInit::GetEnemyVector().size();
	Character& thisEnemy = GameInit::GetEnemyVector()[randEnemy];

	thisEnemy.getSprite().setTextureRect(sf::IntRect(211 * ((rand() % 3) + 1), 0, 211, 320));

	if (thisEnemy.getPosition().y - thisEnemy.getSpeed() > 720 - 120) 
		thisEnemy.setPosition(thisEnemy.getPosition().x, thisEnemy.getPosition().y - thisEnemy.getSpeed());

	if (thisEnemy.getPosition().y - hero.getPosition().y < -thisEnemy.getSpeed())
		thisEnemy.setPosition(thisEnemy.getPosition().x, thisEnemy.getPosition().y + thisEnemy.getSpeed());

	if (thisEnemy.getPosition().y - hero.getPosition().y > thisEnemy.getSpeed())
		thisEnemy.setPosition(thisEnemy.getPosition().x, thisEnemy.getPosition().y - thisEnemy.getSpeed());

	if (thisEnemy.getPosition().x - hero.getPosition().x < -thisEnemy.getSpeed() * 5) {
		thisEnemy.setScale(0.33, 0.33);
		thisEnemy.setPosition(thisEnemy.getPosition().x + thisEnemy.getSpeed(), thisEnemy.getPosition().y);
	}

	if (thisEnemy.getPosition().x - hero.getPosition().x > thisEnemy.getSpeed() * 5) {
		thisEnemy.setScale(-0.33, 0.33);
		thisEnemy.setPosition(thisEnemy.getPosition().x - thisEnemy.getSpeed(), thisEnemy.getPosition().y);
	}

	Logic::clockEnemyMove.restart();
}

void Logic::CharsAttackLogic(MainHero& hero) {
	for (int i = 0; i < GameInit::GetEnemyVector().size(); i++) {
		Character& thisEnemy = GameInit::GetEnemyVector()[i];
		if (Logic::clockEnemyAttack.getElapsedTime().asSeconds() < 2)
			continue;
		if (abs(thisEnemy.getPosition().x - hero.getPosition().x) < thisEnemy.getSpeed() * 5)
			if (abs(thisEnemy.getPosition().y - hero.getPosition().y) < thisEnemy.getSpeed() * 5) {
				hero.setHp(hero.getHp() - (hero.getDefense() >= thisEnemy.getAttack()
					? 0 : thisEnemy.getAttack() - hero.getDefense()));
			}
	}
	if (Logic::clockEnemyAttack.getElapsedTime().asSeconds() > 2)
		Logic::clockEnemyAttack.restart();
}

void Logic::HeroAttackLogic(MainHero& hero) {
	if (hero.getAttackCount() > 0) {
		for (int i = 0; i < GameInit::GetEnemyVector().size(); i++) {
			Character& thisEnemy = GameInit::GetEnemyVector()[i];
			if (abs(thisEnemy.getPosition().x - hero.getPosition().x) < thisEnemy.getSpeed() * 5)
				if (abs(thisEnemy.getPosition().y - hero.getPosition().y) < thisEnemy.getSpeed() * 5) {
					thisEnemy.setHp(thisEnemy.getHp() - (thisEnemy.getDefense() >= hero.getAttack()
						? 0 : hero.getAttack() - thisEnemy.getDefense()));
					if (thisEnemy.getHp() < 0)
						thisEnemy.setAlive(false);
				}
		}
	}
}

void Logic::MoveableLogic() {
	for (int i = 0; i < GameInit::GetMoveableVector().size(); i++) 
		GameInit::GetMoveableVector()[i].moveableUpdate();
}

void Logic::GameLogic(MainHero& hero, sf::RenderWindow& window) {
	Logic::MoveableLogic();
	Logic::CharsMoveLogic(hero, window);
	Logic::CharsAttackLogic(hero);
	Logic::HeroAttackLogic(hero);
	hero.heroUpdate(window);
}
