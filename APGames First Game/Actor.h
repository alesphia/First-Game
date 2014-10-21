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
	static bool isFalling;
	static bool isJumping;
	static float jumpPower;
	static bool hasXCollision;
	static bool hasYCollision;
	//static int x;

	void updatePosition();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void grow(sf::Vector2f);
	void shrink(sf::Vector2f);
	void jump(sf::Time);
	void fall(sf::Time);
	
	void loadTexture();
	void selectActorTileset(int);

	void handleCollision();
};
//sf::Vector2f Actor::size = sf::Vector2f(0.0f, 0.0f);
