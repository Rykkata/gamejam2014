#include "UIGraphicComponent.h"

#include "World.h"
#include "GameObject.h"
#include <iostream>

#define FONT_PATH "Fonts/BlackWolf.ttf"
#define SCORE_Y 40
UIGraphicComponent::UIGraphicComponent() : GraphicComponent()
{
	if (!m_gameFont.loadFromFile(FONT_PATH))
	{
		std::cout << "Error loading font" << std::endl;
	}

	m_playerOneScore.setFont(m_gameFont);
	m_playerOneScore.setString("0");
	m_playerOneScore.setCharacterSize(24);

	m_playerTwoScore.setFont(m_gameFont);
	m_playerTwoScore.setString("0");
	m_playerTwoScore.setCharacterSize(24);

	m_changeWorldMessage.setFont(m_gameFont);
	m_changeWorldMessage.setString("You can edit the game!");
	m_changeWorldMessage.setCharacterSize(16);
	m_changeWorldMessage.setColor(sf::Color::White);
}


UIGraphicComponent::~UIGraphicComponent()
{
}

int UIGraphicComponent::Update(GameObject* object, World* world)
{
	// Update the score strings
	m_playerOneScore.setString(std::to_string(world->playerOneScore));
	m_playerTwoScore.setString(std::to_string(world->playerTwoScore));

	// Set the position for player one score
	sf::Vector2<float> playerOneVector;
	playerOneVector.x = world->renderWindow->getSize().x * 1.0f / 4.0f;
	playerOneVector.y = SCORE_Y;

	// Set the position for player two score
	sf::Vector2<float> playerTwoVector;
	playerTwoVector.x = world->renderWindow->getSize().x  * 3.0f / 4.0f;
	playerTwoVector.y = SCORE_Y;

	// Set the position for the message dialog
	sf::Vector2<float> editWorldVector;
	editWorldVector.x = world->renderWindow->getSize().x * 1.0f / 4.0f;
	editWorldVector.y = world->renderWindow->getSize().y * 7.0f / 8.0f;

	// Set the positions
	m_playerOneScore.setPosition(playerOneVector);
	m_playerTwoScore.setPosition(playerTwoVector);
	m_changeWorldMessage.setPosition(editWorldVector);

	// Display the messages
	world->renderWindow->draw(m_playerOneScore);
	world->renderWindow->draw(m_playerTwoScore);

	if (world->canChangeGame)
		world->renderWindow->draw(m_changeWorldMessage);

	return 0;
}
