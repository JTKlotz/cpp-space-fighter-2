#include "MainMenuScreen.h"
#include "GameplayScreen.h"
#include "DifficultyScreen.h"


DifficultyScreen::DifficultyScreen()
{
	// when the screen is removed, quit the game
	SetOnRemove([this]() { GetGame()->Quit(); });

	SetTransitionInTime(1);
	SetTransitionOutTime(0.5f);

	Show();
}

void DifficultyScreen::LoadContent(ResourceManager& resourceManager)
{
	// Logo
	m_pTexture = resourceManager.Load<Texture>("Textures\\Logo.png");
	m_texturePosition = Game::GetScreenCenter() - Vector2::UNIT_Y * 150;

	// Create the menu items
	//const int COUNT = 2;
	const int COUNT = 3;
	MenuItem* pItem;
	Font::SetLoadSize(20, true);
	Font* pFont = resourceManager.Load<Font>("Fonts\\Ethnocentric.ttf");

	SetDisplayCount(COUNT);

	enum Items { EASY, MEDIUM, HARD };
	std::string text[COUNT] = { "Easy", "Medium", "Hard" };

	for (int i = 0; i < COUNT; i++)
	{
		pItem = new MenuItem(text[i]);
		pItem->SetPosition(Vector2(100, 100 + 50 * i));
		pItem->SetFont(pFont);
		pItem->SetColor(Color::BLUE);
		pItem->SetSelected(i == 0);
		AddMenuItem(pItem);
	}

	// when "Start Game" is selected, replace the "SetRemoveCallback" delegate
	// so that it doesn't quit the game (originally set in the constructor)
	// Select a difficulty
	GetMenuItem(EASY)->SetOnSelect([this]() {
		SetOnRemove([this]() { AddScreen(new GameplayScreen(0)); });
		Exit();
		});


	GetMenuItem(MEDIUM)->SetOnSelect([this]() {
		SetOnRemove([this]() { AddScreen(new GameplayScreen(1)); });
		Exit();
		});

	GetMenuItem(HARD)->SetOnSelect([this]() {
		SetOnRemove([this]() { AddScreen(new GameplayScreen(2)); });
		Exit();
		});
}

void DifficultyScreen::Update(const GameTime& gameTime)
{
	bool isSelected = false;
	float alpha = GetAlpha();
	float offset = sinf(gameTime.GetTotalTime() * 10) * 5 + 5;

	for (MenuItem* pItem : GetMenuItems())
	{
		pItem->SetAlpha(alpha);
		isSelected = pItem->IsSelected();
		pItem->SetColor(isSelected ? Color::GREEN : Color::RED);
		pItem->SetTextOffset(isSelected ? Vector2::UNIT_X * offset : Vector2::ZERO);
	}

	MenuScreen::Update(gameTime);
}

void DifficultyScreen::Draw(SpriteBatch& spriteBatch)
{
	spriteBatch.Begin();
	spriteBatch.Draw(m_pTexture, m_texturePosition, Color::WHITE * GetAlpha(), m_pTexture->GetCenter());
	MenuScreen::Draw(spriteBatch);
	spriteBatch.End();
}