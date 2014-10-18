

#include "stdafx.h"
#include "Actor.h"
#include <SFML/Graphics.hpp>
#include <iostream>



sf::Sprite  Actor::sprite = sf::Sprite();
sf::Vector2f Actor::position = sf::Vector2f();
sf::Vector2f Actor::speed = sf::Vector2f();
sf::Vector2f Actor::scale = sf::Vector2f(1.0f , 1.0f);
sf::Vector2f Actor::size = sf::Vector2f();
sf::Texture Actor::texture = sf::Texture();
sf::IntRect Actor::tile = sf::IntRect(96, 128, 32, 32);
int Actor::animationCounter = 0;


Actor::Actor()
{

	Actor(sf::Vector2i(800, 600), 60);

}


Actor::~Actor()
{
}

Actor::Actor(sf::Vector2i resolution, int frameRateMax)
{
	
//	set actor's default draw size in pixels
	Actor::size.x = resolution.x * 0.07f;
	Actor::size.y = resolution.y * 0.11f;

//	set actor's default speed in pixels
	Actor::speed.x = 1.0f;//frameRateMax * 0.04f;
	Actor::speed.y = frameRateMax * 0.04f;

//	set actor start position
	Actor::position.x = resolution.x / 2.0f;
	Actor::position.y = resolution.y / 2.0f;

//	load a texture to be assigned to actor
	loadTexture();

//	assign actor a texture
	
	sprite.setTextureRect(tile);
	sprite.setTexture(texture);

}

void Actor::loadTexture(){

//  load a texture into a texture type to be assigned to this actor
	
	if (!texture.loadFromFile("Spiritual.png"))
	{
		std::cerr << "The texture didn't load." << std::endl;
	}
	texture.setSmooth(true);

}

void Actor::moveLeft(){

//	Change the position of the sprite
	Actor::position.x -= Actor::speed.x;
	Actor::sprite.setPosition(Actor::position.x, Actor::position.y);
	
	
	
//	play the appropriate sprite animations
	sprite.setTextureRect(sf::IntRect(  (tile.left + animationCounter),
										(tile.top + tile.height),
										 tile.width,
										 tile.height));

}

void Actor::moveRight(){

	Actor::position.x += Actor::speed.x;
	Actor::sprite.setPosition(Actor::position.x, Actor::position.y);

	
	sprite.setTextureRect(sf::IntRect( (tile.left + animationCounter),
										tile.top + (2 * tile.height),
										tile.width,
										tile.height));

};

void Actor::moveUp(){

	Actor::position.y -= Actor::speed.y;
	Actor::sprite.setPosition(Actor::position.x, Actor::position.y);

};

void Actor::moveDown(){

	Actor::position.y += Actor::speed.y;
	Actor::sprite.setPosition(Actor::position.x, Actor::position.y);

};

void Actor::grow(sf::Vector2f rate){

	sprite.setScale(scale.x += rate.x , scale.y += rate.y);

};

void Actor::shrink(sf::Vector2f rate){

	if (sprite.getScale().x <= 0 || sprite.getScale().y <= 0) 
		return;

	sprite.setScale(scale.x -= rate.x, scale.y -= rate.y);

};

void Actor::selectActorTileset(int selction = 0){

	switch (selction) {

	case 0:
		tile = sf::IntRect(0, 0, 32, 32);
		break;
	case 1:
		tile = sf::IntRect(0, 128, 32, 32);
		break;
	case 2:
		tile = sf::IntRect(96, 0, 32, 32);
		break;
	case 3:
		tile = sf::IntRect(96, 128, 32, 32);
		break;
	case 4:
		tile = sf::IntRect(192, 0, 32, 32);
		break;
	case 5:
		tile = sf::IntRect(192, 128, 32, 32);
		break; 
	case 6:
		tile = sf::IntRect(288, 0, 32, 32);
		break;
	case 7:
		tile = sf::IntRect(288, 128, 32, 32);
		break;
	}

}
