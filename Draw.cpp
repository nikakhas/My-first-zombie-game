#include "Draw.h"

void Draw::DrawLevel(sf::RenderWindow& window, MainHero& hero) {

	window.draw(GameInit::GetBackground().getSprite());

	for (int i = 0; i < GameInit::GetMoveableVector().size(); i++)
		GameInit::GetMoveableVector()[i].drawSprite(window);

	for (int i = 0; i < GameInit::GetLevelVector().size(); i++)
		GameInit::GetLevelVector()[i].drawSprite(window);

	for (int i = 0; i < GameInit::GetDoorVector().size(); i++)
		GameInit::GetDoorVector()[i].drawSprite(window);

	for (int i = 0; i < GameInit::GetEnemyVector().size(); i++)
		GameInit::GetEnemyVector()[i].drawSprite(window);

	if (hero.getAlive())
		hero.drawSprite(window);

	window.display();
}