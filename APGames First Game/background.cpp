#include "StdAfx.h"
#include "background.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Sprite Background::behind = sf::Sprite();
sf::Vector2f Background::position = sf::Vector2f();
sf::Vector2f Background::size = sf::Vector2f();
sf::Texture Background::back = sf::Texture();
sf::IntRect Background::tile = sf::IntRect(0, 0, 800, 475);


Background::Background()
{
	Background(sf::Vector2i(800, 600), 60);
}
Background::~Background()
{
}
Background::Background(sf::Vector2i resolution, int frameRateMax)
{
	Background::size.x = 800;
	Background::size.y = 495;

	Background::position.x = 0;
	Background::position.y = 0;

	loadTexture();

	behind.setTextureRect(tile);
	behind.setTexture(back);
}

void Background::loadTexture()
{
	// load a texture into a texture type to be assigned to this actor
	if (!back.loadFromFile("background.jpg"))
	{
		
	}
	
	
};
