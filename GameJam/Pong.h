#pragma once
#include <SFML/Graphics.hpp>



class Pong
{
public:;
	static Pong& GetInstance(void);
	~Pong();
	void RunGame(void);
private:
	sf::Time m_timer;
};

