// APGames First Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Actor.h"

void handlePlayerInput(Actor&);


int main(int argc, _TCHAR* argv[])
{
	int frameRateMax = 60;
	
	sf::Vector2i resolution;
	resolution.x = 800;
	resolution.y = 600;
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

void handlePlayerInput(Actor &player){
	
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
}

