#include "Pong.h"

// World
#include "World.h"

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
#define BALL_PATH "Sprites/Ball.png"

// The player constants
#define PLAYER_X 720
#define PLAYER_Y 300

// The AI constants
#define AI_X 60
#define AI_Y 20

// The ball constants
#define BALL_X 395
#define BALL_Y 295
#define BALL_X_VEL 200
#define BALL_Y_VEL 50

// The tick rate, handle for 60 FPS
#define TICK_RATE 16667

// Max Score of the game
#define MAX_SCORE 10

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
	bool didPlayerWin = false;
	m_usingKeyboard = true;
	m_isGameRunning = true;
	bool displayEndScreen = false;
	// Create the game world
	World* gameWorld = new World();
	
	// Create the player and set its position
	Player* player = new Player(new PlayerEventComponent(), new MoveableGraphicComponent(PADDLE_PATH), new MoveablePhysicComponent());
	player->tag = "Player";

	// Create the AI and set its position
	AI* ai = new AI(new AIEventComponent(), new MoveableGraphicComponent(PADDLE_PATH), new MoveablePhysicComponent());
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
					gameWorld->renderWindow->close();

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
			sf::Event event;
			while (gameWorld->renderWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					gameWorld->renderWindow->close();

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
		}
	}
}
