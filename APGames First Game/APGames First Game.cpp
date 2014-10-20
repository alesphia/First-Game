// APGames First Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Actor.h"

void handlePlayerInput(Actor&);


int main(int argc, CHAR* argv[])
{
	int frameRateMax = 60;
	
	sf::Vector2i resolution;
	resolution.x = 1024;
	resolution.y = 720;
	Actor player(resolution, frameRateMax);
	
	
	
	////hide console////
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	///////////////////


	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "APGames Programming Challenge 3");
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(frameRateMax);

	/////////////////////////////////////////////////////////////////
	/////////////logic loop//////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	int loopIteration = 0;

	while (window.isOpen())
	{
		if (player.animationCounter > 62)
		{
			player.animationCounter = 0;
			loopIteration = 0;
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		handlePlayerInput(player);
		
		window.clear();
		window.draw(player.sprite);   //earlier drawn is occluded by later drawn, want player on top so draw later
		window.display();
		
		if(loopIteration++ % 15 == 0) player.animationCounter += 31;
		
	}
	/////////////////////////////////////////////////////////////////

	return 0;

}

inline void handlePlayerInput(Actor &player){
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		player.grow(sf::Vector2f(0.1f, 0.1f));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && player.scale.x >= 0 && player.scale.y >= 0)
	{

		player.shrink(sf::Vector2f(0.1f, 0.1f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		player.moveLeft();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.moveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.moveUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.moveDown();
	}


////////////////////////////////////////////////////////////////////////
///////////////test tileset selection for actor/////////////////////////
////////////////////////////////////////////////////////////////////////

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
	{
		player.selectActorTileset(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{
		player.selectActorTileset(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		player.selectActorTileset(2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	{
		player.selectActorTileset(3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		player.selectActorTileset(4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
	{
		player.selectActorTileset(5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		player.selectActorTileset(6);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
	{
		player.selectActorTileset(7);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player.jump();
	}
///////////////////////////////////////////////////////////////////////////


}

