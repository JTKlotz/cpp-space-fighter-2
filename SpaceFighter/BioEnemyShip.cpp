
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip(const int difficulty)
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
	SetLevelDifficulty(difficulty);
}


void BioEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{

		if (m_Difficulty == 0)
		{
			float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

			TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());
		}
		//editing position: trying to change the direction that the ships appear(L -> R)
		//These edits change the direction from L -> R

		if (m_Difficulty == 1)
		{
			/*float y = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			y *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

			TranslatePosition(GetSpeed() * gameTime.GetElapsedTime(), y);*/

			float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			x *= GetSpeed() * gameTime.GetElapsedTime() * 3.0f;

			TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());
		}

		if (m_Difficulty == 2)
		{
			/*float y = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			y *= GetSpeed() * gameTime.GetElapsedTime() * 5.0f;

			TranslatePosition(GetSpeed() * gameTime.GetElapsedTime(), y);*/
			float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());

			x *= GetSpeed() * gameTime.GetElapsedTime() * 5.0f;

			TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());
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
