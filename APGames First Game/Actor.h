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
	static sf::IntRect tile;
	static int animationCounter;
	static bool isFalling;
	static bool isJumping;
	static float jumpPower;
	static bool hasXCollision;
	static bool hasYCollision;

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
	void checkCollision(int map[], int);
	void handleCollision();
//	void handleCollision(sf::Rect<float>, sf::Rect<float>);

};

