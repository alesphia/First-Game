#pragma once
#include "SFML/Graphics.hpp"
class Background
{
public:
	Background();
	~Background();
	Background(sf::Vector2i, int);
	static sf::Sprite behind;
	static sf::Vector2f position;
	static sf::Vector2f size;
	static int animationCounter;
	static sf::Texture back;
	static sf::IntRect tile;
	void loadTexture();
};
