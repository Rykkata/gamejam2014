#pragma once
#include "GraphicComponent.h"
class UIGraphicComponent :
	public GraphicComponent
{
public:
	UIGraphicComponent();
	~UIGraphicComponent();
	virtual int Update(GameObject* gameObject, World* world);
private:
	sf::Font m_gameFont;
	sf::Text m_playerOneScore;
	sf::Text m_playerTwoScore;
	sf::Text m_changeWorldMessage;
	sf::Sprite m_paddleSize;
	sf::Sprite m_paddleSpeed;
	sf::Sprite m_ballSize;
	sf::Sprite m_ballSpeed;
	sf::Sprite m_selected;
};

