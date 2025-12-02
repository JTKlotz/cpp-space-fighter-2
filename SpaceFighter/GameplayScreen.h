
#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class Level;

/** @brief The gameplay screen for the Space Fighter Game.
	It is responsible for creating and loading levels.
	@see Level
	@see Screen
*/
class GameplayScreen : public Screen
{

public:

	//method added to get the level index for scene transition/main menu
	virtual int GetLevelIndex() const { return m_levelIndex; }

	/** @brief Instantiate a gameplay screen object.
		@param levelIndex The index of the level to load. */
	GameplayScreen(const int levelDifficulty, const int levelIndex = 0);
	virtual ~GameplayScreen() { }

	/** @brief Load the content for the screen.
		@param resourceManager A reference to the game's resource manager. */
	virtual void LoadContent(ResourceManager& resourceManager);

	/** @brief Handle input for the screen.
		@param input The current state of all player input devices. */
	virtual void HandleInput(const InputState& input);

	virtual void SetDifficulty(const int difficulty) { m_LevelDifficulty = difficulty; }

	/** @brief Update the screen.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Render the screen.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Load a specific level.
		@param levelIndex The index of the level to load. */
	virtual void LoadLevel(const int levelIndex);

	//added to persist across each level
	virtual int GetNextLevelValue() { return m_nextLevelValue; }
	virtual void SetNextLevelValue(int value) { m_nextLevelValue = value; }

private:

	//added as a member variable, to persist
	int m_nextLevelValue = 0;

	int m_levelIndex = 0;

	int m_LevelDifficulty;

	Level *m_pLevel = nullptr;

	ResourceManager *m_pResourceManager = nullptr;

};
