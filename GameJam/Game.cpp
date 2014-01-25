#include "Game.h"



Game& Game::GetInstance(void)
{
	static Game instance;

	return instance;
}

Game::~Game()
{
}

void Game::RunGame(void)
{
	sf::RenderWindow window;
	sf::VideoMode resolution = sf::VideoMode(1024, 768);
	window.create(resolution, "Game Jam");

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time deltaTime = gameClock.restart();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.clear();
		window.display();
	}
}
