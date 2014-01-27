#include "Pong.h"

// World
#include "World.h"
#include "SFML\Audio.hpp"
// Player Components
#include "Player.h"
#include "PlayerEventComponent.h"

// AI Components
#include "AI.h"
#include "AIEventComponent.h"

// Ball Components
#include "Ball.h"
#include "BallPhysicComponent.h"
#include "NPCEventComponent.h"


// UI Components
#include "UI.h"
#include "UIGraphicComponent.h"
#include "UIEventComponent.h"
#include "StaticPhysicComponent.h"

// Moveable Components
#include "MoveablePhysicComponent.h"
#include "MoveableGraphicComponent.h"

// The graphic paths
#define PADDLE_PATH "Sprites/Paddle.png"
#define PLAYER_PATH "Sprites/PlayerPaddle.png"
#define AI_PATH "Sprites/AIPaddle.png"
#define BALL_PATH "Sprites/Ball.png"
#define FONT_PATH "Fonts/BlackWolf.ttf"

// The BGM file path
#define BGM_PATH "Music/BGM.ogg"

// The tick rate, handle for 60 FPS
#define TICK_RATE 16667

// Max Score of the game
#define MAX_SCORE 10

//End Screen stuff
#define END_X 150
#define END_Y 60

Pong& Pong::GetInstance(void)
{
	static Pong instance;

	return instance;
}

Pong::~Pong()
{
}

void Pong::RunGame(void)
{
	sf::Clock gameClock;
	sf::Music BGM;
	BGM.openFromFile(BGM_PATH);
	bool didPlayerWin = false;
	m_usingKeyboard = true;
	m_isGameRunning = true;
	bool displayEndScreen = false;
	// Create the game world
	World* gameWorld = new World();
	
	// Create the player and set its position
	Player* player = new Player(new PlayerEventComponent(), new MoveableGraphicComponent(PLAYER_PATH), new MoveablePhysicComponent());
	player->tag = "Player";

	// Create the AI and set its position
	AI* ai = new AI(new AIEventComponent(), new MoveableGraphicComponent(AI_PATH), new MoveablePhysicComponent());
	ai->tag = "AI";

	// Create the ball and set it up
	Ball* ball = new Ball(new NPCEventComponent(), new MoveableGraphicComponent(BALL_PATH), new BallPhysicComponent());
	ball->tag = "Ball";

	// Create the UI and set it up
	UI* ui = new UI(new UIEventComponent(), new UIGraphicComponent(), new StaticPhysicComponent());

	// Add the objects to the world
	gameWorld->AddObject(player);
	gameWorld->AddObject(ai);
	gameWorld->AddObject(ball);
	gameWorld->AddObject(ui);

	// Don't repeat keystrokes
	gameWorld->renderWindow->setKeyRepeatEnabled(false);

	// Start the game
	gameWorld->ResetObjects(false);
	BGM.setLoop(true);
	BGM.setVolume(25.0f);
	BGM.play();
	// Run the game
	while (gameWorld->renderWindow->isOpen())
	{
		while (m_isGameRunning)
		{

			gameWorld->deltaTime = gameClock.restart();
			GameObject::message = NONE;

			sf::Event event;
			while (gameWorld->renderWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_isGameRunning = false;
					displayEndScreen = false;
					BGM.stop();
					gameWorld->renderWindow->close();
				}
					

				if (m_usingKeyboard && event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Left)
						GameObject::message = LEFT;

					if (event.key.code == sf::Keyboard::Right)
						GameObject::message = RIGHT;

					if (event.key.code == sf::Keyboard::Up)
						GameObject::message = UP;

					if (event.key.code == sf::Keyboard::Down)
						GameObject::message = DOWN;
				}
			}

			// Redraw the screen and update the objects
			gameWorld->renderWindow->clear();
			gameWorld->DrawBackground();
			gameWorld->UpdateObjects();
			gameWorld->renderWindow->display();
			if (gameWorld->playerOneScore >= MAX_SCORE)
			{
				didPlayerWin = false;
				m_isGameRunning = false;
				displayEndScreen = true;
				gameWorld->renderWindow->clear();
				gameWorld->renderWindow->display();
			}
			else if (gameWorld->playerTwoScore >= MAX_SCORE)
			{
				didPlayerWin = true;
				m_isGameRunning = false;
				displayEndScreen = true;
				gameWorld->renderWindow->clear();
				gameWorld->renderWindow->display();
			}
		}

		while (displayEndScreen)
		{
			sf::Font gameFont;
			gameFont.loadFromFile(FONT_PATH);
			sf::Text statusMessage;
			statusMessage.setFont(gameFont);
			if (didPlayerWin)
				statusMessage.setString("You Won! Good job!");
			else
				statusMessage.setString("You lost... Try Again!");
			statusMessage.setCharacterSize(48);
			statusMessage.setPosition(END_X, END_Y);

			sf::Text playAgain;
			playAgain.setFont(gameFont);
			playAgain.setString("Press R to play again!");
			playAgain.setPosition(END_X, END_Y + 200);
			sf::Event event;
			while (gameWorld->renderWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					BGM.stop();
					m_isGameRunning = false;
					displayEndScreen = false;
					gameWorld->renderWindow->close();	
				}
					
				if (m_usingKeyboard && event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::R)
					{
						gameWorld->playerOneScore = 0;
						gameWorld->playerTwoScore = 0;
						displayEndScreen = false;
						m_isGameRunning = true;
						gameWorld->ResetObjects(false);
						gameWorld->ResetModifers();
					}
				}
			}

			gameWorld->renderWindow->clear();
			gameWorld->renderWindow->draw(statusMessage);
			gameWorld->renderWindow->draw(playAgain);
			gameWorld->renderWindow->display();
		}
	}

	// clean up
	delete gameWorld;
	delete player;
	delete ai;
	delete ball;
	delete ui;
}
