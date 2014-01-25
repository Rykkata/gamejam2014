#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
	static Game& GetInstance(void);
	~Game();
	void RunGame(void);
private:
	int frames; 
	sf::Clock gameClock;
};

