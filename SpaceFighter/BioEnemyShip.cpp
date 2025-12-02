
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip(const int difficulty, const int direction)
{
	SetShipDirection(direction);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
	SetSpeed(150*difficulty);
}


void BioEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{

		if (m_ShipDirection == 1)
		{
			float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

			TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());
		}
		
		//editing position: trying to change the direction that the ships appear(L -> R)
		//These edits change the direction from L -> R
		if (m_ShipDirection == 2)
		{
			float y = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			y *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

			TranslatePosition(GetSpeed() * gameTime.GetElapsedTime(), y);

		}

		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(gameTime);
}


void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
