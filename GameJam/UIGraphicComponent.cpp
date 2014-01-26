#include "UIGraphicComponent.h"

#include "World.h"
#include "GameObject.h"
#include <iostream>

#define FONT_PATH "Fonts/BlackWolf.ttf"
#define PADDLE_SIZE "Sprites/PaddleSize.png"
#define PADDLE_SPEED "Sprites/PaddleSpeed.png"
#define BALL_SIZE "Sprites/BallSize.png"
#define BALL_SPEED "Sprites/BallSpeed.png"
#define SELECTOR "Sprites/Selector.png"

#define MOD_Y 

#define SCORE_Y 40.0f
#define BASE_X 340.0f
#define MOD_X  30.0f
#define SELECT_Y 555.0f

#define DRAW world->renderWindow->draw

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

	sf::Texture* paddleSize = new sf::Texture;
	paddleSize->loadFromFile(PADDLE_SIZE);
	m_paddleSize.setTexture(*paddleSize);
	m_paddleSize.setPosition(BASE_X, SELECT_Y);

	sf::Texture* paddleSpeed = new sf::Texture;
	paddleSpeed->loadFromFile(PADDLE_SPEED);
	m_paddleSpeed.setTexture(*paddleSpeed);
	m_paddleSpeed.setPosition(BASE_X + MOD_X, SELECT_Y);

	sf::Texture* ballSize = new sf::Texture;
	ballSize->loadFromFile(BALL_SIZE);
	m_ballSize.setTexture(*ballSize);
	m_ballSize.setPosition(BASE_X + MOD_X * 2, SELECT_Y);

	sf::Texture* ballSpeed = new sf::Texture;
	ballSpeed->loadFromFile(BALL_SPEED);
	m_ballSpeed.setTexture(*ballSpeed);
	m_ballSpeed.setPosition(BASE_X + MOD_X * 3, SELECT_Y);

	sf::Texture* selector = new sf::Texture;
	selector->loadFromFile(SELECTOR);
	m_selected.setTexture(*selector);
	m_selected.setPosition(BASE_X, SELECT_Y);
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

	m_selected.setPosition(BASE_X + MOD_X * GameObject::attribute, SELECT_Y);

	// Display the messages
	DRAW(m_playerOneScore);
	DRAW(m_playerTwoScore);

	// Display the modifiers
	DRAW(m_paddleSize);
	DRAW(m_paddleSpeed);
	DRAW(m_ballSize);
	DRAW(m_ballSpeed);
	DRAW(m_selected);

	if (world->canChangeGame)
		DRAW(m_changeWorldMessage);

	return 0;
}
