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
};

