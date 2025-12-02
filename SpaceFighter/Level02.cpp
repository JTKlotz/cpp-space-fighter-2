

#include "Level02.h"
#include "BioEnemyShip.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	const int COUNT = 22;
	int direction;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55, .6
	};

	// new array of positions for hard difficulty
	double yPositions[COUNT] =
	{
		0.35, 0.25, 0.3,
		0.6, 0.55, 0.65,
		0.3, 0.3, 0.45, 0.3, 0.5,
		0.6, 0.65, 0.5, 0.65, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55
	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	if (m_LevelDifficulty == 3)
	{
		// make the enemy appear normally
		direction = 1;
		for (int i = 0; i < COUNT / 2; i++)
		{
			delay += delays[i];
			position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

			BioEnemyShip* pEnemy = new BioEnemyShip(m_LevelDifficulty, direction);
			pEnemy->SetTexture(pTexture);
			pEnemy->SetCurrentLevel(this);
			pEnemy->Initialize(position, (float)delay);
			AddGameObject(pEnemy);
		}

		// change the direction the enemy appear 
		direction = 2;
		for (int i = COUNT / 2; i < COUNT; i++)
		{
			delay += delays[i];
			direction = 2;
			position.Set(-pTexture->GetCenter().X, xPositions[i] * Game::GetScreenHeight());

			BioEnemyShip* pEnemy = new BioEnemyShip(m_LevelDifficulty, direction);
			pEnemy->SetTexture(pTexture);
			pEnemy->SetCurrentLevel(this);
			pEnemy->Initialize(position, (float)delay);
			AddGameObject(pEnemy);
		}
	}
	else
	{
		// make the enemy appear normally
		direction = 1;
		for (int i = 0; i < COUNT; i++)
		{
			delay += delays[i];
			position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

			BioEnemyShip* pEnemy = new BioEnemyShip(m_LevelDifficulty, direction);
			pEnemy->SetTexture(pTexture);
			pEnemy->SetCurrentLevel(this);
			pEnemy->Initialize(position, (float)delay);
			AddGameObject(pEnemy);
		}
	}

	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground01.png"));
	Level::LoadContent(resourceManager);
}

