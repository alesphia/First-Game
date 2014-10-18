#pragma once
#include "SFML/Graphics.hpp"
class Actor
{
public:
	Actor();
	~Actor();
	Actor(sf::Vector2i, int);

	static sf::Sprite sprite;
	static sf::Vector2f position;
	static sf::Vector2f speed;
	static sf::Vector2f scale;
	static sf::Vector2f size;
	static sf::Texture texture;
	static sf::IntRect tile;// = sf::IntRect(96, 128, 32, 32);
	static int animationCounter;
	//static int x;

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void grow(sf::Vector2f);
	void shrink(sf::Vector2f);
	
	void loadTexture();
	void selectActorTileset(int);
};
//sf::Vector2f Actor::size = sf::Vector2f(0.0f, 0.0f);
