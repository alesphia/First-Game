#pragma once
#include <SFML/System.hpp>
class GameClock
{
public:
	GameClock();
	~GameClock();

	static sf::Clock timer;
	static sf::Time elapsedTime;

};

