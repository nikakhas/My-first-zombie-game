#include "GameInit.h"
Object GameInit::grassGradient;
Object GameInit::background;
map <enumTextures, sf::Texture> GameInit::gameTextures;
vector<Object> GameInit::doorVector;
vector<Object> GameInit::levelVector;
vector<Character> GameInit::enemyVector;
vector<Moveable> GameInit::moveableVector;

Object& GameInit::GetGrassGradient() {
	return GameInit::grassGradient;
}

vector<Moveable>& GameInit::GetMoveableVector() {
	return GameInit::moveableVector;
}

Object& GameInit::GetBackground() {
	return GameInit::background;
}

vector<Object>& GameInit::GetLevelVector() {
	return GameInit::levelVector;
}

vector<Object>& GameInit::GetDoorVector() {
	return GameInit::doorVector;
}

vector<Character>& GameInit::GetEnemyVector() {
	return GameInit::enemyVector;
}

sf::Texture& GameInit::GetTexture(enumTextures key) {
	return GameInit::gameTextures[key];
}

void GameInit::InitTextures() {

	sf::Texture background;
	background.loadFromFile("Sprites/Background.jpg");
	GameInit::gameTextures[enumTextures::background] = background;
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Sprites/person.png");
	GameInit::gameTextures[enumTextures::playerTexture] = playerTexture;

	sf::Texture zombie;
	zombie.loadFromFile("Sprites/zombie.png");
	GameInit::gameTextures[enumTextures::enemyTexture] = zombie;

	sf::Texture mapTexture;
	mapTexture.loadFromFile("Sprites/map.png");
	GameInit::gameTextures[enumTextures::mapTexture] = mapTexture;

	sf::Texture grassGradient;
	grassGradient.loadFromFile("Sprites/GrassGradient.jpg");
	GameInit::gameTextures[enumTextures::grassGradientTexture] = grassGradient;

	sf::Texture cloud;
	cloud.loadFromFile("Sprites/cloud.png");
	GameInit::gameTextures[enumTextures::cloud] = cloud;

	sf::Texture bigCloud;
	bigCloud.loadFromFile("Sprites/BigCloud.png");
	GameInit::gameTextures[enumTextures::bigCloud] = bigCloud;

}

void GameInit::InitMap(sf::RenderWindow& window) {
	int windowSizeX = window.getSize().x;
	int windowSizeY = window.getSize().y;

	GameInit::background.setPosition(0, 0);
	GameInit::background.getSprite().setTexture(GameInit::GetTexture(enumTextures::background));
	GameInit::background.getSprite().setTextureRect(sf::IntRect(0, 0, windowSizeX, windowSizeY));

	GameInit::grassGradient.setPosition(0, windowSizeY - 390);
	GameInit::grassGradient.getSprite().setTexture(GameInit::gameTextures[enumTextures::grassGradientTexture]);
	GameInit::grassGradient.getSprite().setTextureRect(sf::IntRect(0, 0, windowSizeX, 300));
	GameInit::grassGradient.setOrigin(0, grassGradient.getHeight());
	GameInit::levelVector.push_back(grassGradient);

	Moveable cloud(GameInit::GetTexture(enumTextures::cloud), sf::IntRect(0, 0, 588, 488), windowSizeX / 25, windowSizeY - 600, false, 20);
	cloud.getSprite().setTexture(GameInit::GetTexture(enumTextures::cloud));
	cloud.getSprite().setTextureRect(sf::IntRect(0, 0, 588, 488));
	cloud.setScale(0.3, 0.3);
	cloud.moveMoveable(true, 15);
	GameInit::moveableVector.push_back(cloud);

	Moveable bigCloud(GameInit::GetTexture(enumTextures::bigCloud), sf::IntRect(0, 0, 1000, 426), windowSizeX / 2, windowSizeY - 670, false, 20);
	bigCloud.getSprite().setTexture(GameInit::GetTexture(enumTextures::bigCloud));
	bigCloud.getSprite().setTextureRect(sf::IntRect(0, 0, 1000, 426));
	bigCloud.setScale(0.3, 0.3);
	bigCloud.moveMoveable(true, 10);
	GameInit::moveableVector.push_back(bigCloud);

	float grassPosX = 0;
	float grassPosY = windowSizeY - 139;
	float soilPosX = 0;
	float soilPosY = windowSizeY - 70;
	float fencePosX = 0;
	float fencePosY = GameInit::GetGrassGradient().getPosition().y - GameInit::GetGrassGradient().getHeight() - 70;

	while (grassPosX < windowSizeX) {

		Object grass(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(504, 574, 72, 70), grassPosX, grassPosY, true);
		grass.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
		grass.getSprite().setTextureRect(sf::IntRect(504, 574, 72, 70));
		GameInit::levelVector.push_back(grass);
		grassPosX += grass.getWidth() - 3;

		Object soil(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(576, 864, 72, 70), soilPosX, soilPosY, true);
		soil.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
		soil.getSprite().setTextureRect(sf::IntRect(576, 864, 72, 70));
		GameInit::levelVector.push_back(soil);
		soilPosX += soil.getWidth() - 3;

		Object fence(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(648, 142, 72, 70), fencePosX, fencePosY, false);
		fence.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
		fence.getSprite().setTextureRect(sf::IntRect(648, 142, 72, 70));
		if (fencePosX == 213)
			fence.getSprite().setTextureRect(sf::IntRect(648, 71, 72, 70));
		GameInit::levelVector.push_back(fence);
		fencePosX += fence.getWidth() - 1;

	}

	float wallPosX = windowSizeX - 4 * 70;
	float wallPosY = GameInit::GetGrassGradient().getPosition().y - GameInit::GetGrassGradient().getHeight() - 72 + 2;
	while (wallPosY > 0 || wallPosX < windowSizeX) {
		if (wallPosX > windowSizeX) {
			wallPosX = windowSizeX - 4 * 70;
			wallPosY -= 72 - 4;
		}
		Object wall(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(504, 286, 72, 70), wallPosX, wallPosY, false);
		wall.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
		wall.getSprite().setTextureRect(sf::IntRect(504, 286, 72, 70));
		GameInit::levelVector.push_back(wall);
		wallPosX += wall.getWidth() - 2;
	}

	float windowsPosY = 72;
	
	Object windows(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(64, 4, 72, 70), window.getSize().x -
		3 * 70, windowsPosY, false);
	windows.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
	windows.getSprite().setTextureRect(sf::IntRect(70, 4, 72, 70));
	GameInit::levelVector.push_back(windows);

	Object fire(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(70, 144, 72, 70), window.getSize().x -
		4 * 70, windowsPosY - 2, false);
	fire.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
	fire.getSprite().setTextureRect(sf::IntRect(70, 144, 72, 70));
	GameInit::levelVector.push_back(fire);
	
	int doorPosY = GameInit::GetGrassGradient().getPosition().y - GameInit::GetGrassGradient().getHeight() - 72 + 2;
	Object doorDown(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(647, 432, 72, 70), window.getSize().x -
	3 * 70 + 45, doorPosY, false);
	doorDown.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
	doorDown.getSprite().setTextureRect(sf::IntRect(647, 432, 72, 70));
	GameInit::doorVector.push_back(doorDown);

	doorPosY -= doorDown.getHeight() - 2;

	Object doorUp(GameInit::GetTexture(enumTextures::mapTexture), sf::IntRect(647, 360, 72, 70), window.getSize().x -
		3 * 70 + 45, doorPosY, false);
	doorUp.getSprite().setTexture(GameInit::GetTexture(enumTextures::mapTexture));
	doorUp.getSprite().setTextureRect(sf::IntRect(647, 360, 72, 70));
	GameInit::doorVector.push_back(doorUp);
}

void GameInit::InitChars(sf::RenderWindow& window) {

	std::random_device randDevice;
	std::mt19937 eng(randDevice());
	std::uniform_int_distribution<> distrY(GameInit::GetGrassGradient().getPosition().y + 10, window.getSize().y - 150);
	std::uniform_int_distribution<> distrX(window.getSize().x / 3, window.getSize().x - 30);

	for (int i = 0; i < 5; i++) {
		Character enemy(GameInit::GetTexture(enumTextures::enemyTexture),
			sf::IntRect(0, 0, 205, 320), 0, 0, false, 15, 100, 20, 5, true);
		enemy.setOrigin(enemy.getWidth() / 2, enemy.getHeight());
		int randX = (distrX(eng));
		int randY = (distrY(eng));
		enemy.setAlive(true);
		enemy.setPosition(randX, randY);
		enemy.getSprite().setTexture(GameInit::GetTexture(enumTextures::enemyTexture));
		enemy.getSprite().setTextureRect(sf::IntRect(0, 0, 205, 320));
		enemy.setScale(0.33, 0.33);
		enemy.setOrigin(enemy.getWidth() / 2, enemy.getHeight());
		GameInit::enemyVector.push_back(enemy);
	}
}