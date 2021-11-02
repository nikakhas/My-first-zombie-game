#pragma once
#include "MainHero.h"

enum class enumTextures {
	mapTexture,
	playerTexture,
	enemyTexture,
	grassGradientTexture,
	background,
	cloud,
	bigCloud
};

static class GameInit {
	static Object background;
	static Object grassGradient;
	static map <enumTextures, sf::Texture> gameTextures;
	static vector<Object> doorVector;
	static vector<Object> levelVector;
	static vector<Character> enemyVector;
	static vector<Moveable> moveableVector;
public:
	static vector<Moveable>& GetMoveableVector();
	static Object& GetBackground();
	static Object& GetGrassGradient();
	static vector<Object>& GetLevelVector();
	static vector<Object>& GetDoorVector();
	static vector<Character>& GetEnemyVector();
	static sf::Texture& GetTexture(enumTextures key);
	static void InitTextures();
	static void InitMap(sf::RenderWindow& window);
	static void InitChars(sf::RenderWindow& window);
};