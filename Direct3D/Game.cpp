#include "Game.h"

Game::Game()
{

}

bool Game::Initialize(HWND hWnd)
{
	gDevice = new GraphicsDevice();

	if (!gDevice->Initialize(hWnd, true))
	{
		return false;
	}

	player = new GameplayObject(100, 200, (float)M_PI_4, 90.0f, 90.0f);

	if (!player->Initialize(gDevice->device, "PlayerPaper.png", 58, 86))
	{
		return false;
	}

	player2 = new GameplayObject(80, 200, 0, 90.0f, 90.0f);

	if (!player2->Initialize(gDevice->device, "PlayerPaper.png", 58, 86))
	{
		return false;
	}

	gameTime = new GameTime();
	if (!gameTime->Initialize())
	{
		return false;
	}

	return true;
}

void Game::Run()
{
	//Get game time and update + draw
	gameTime->Update();

	Update(gameTime->elapsedGameTime);
	Draw(gameTime->elapsedGameTime);
}

void Game::Update(float gameTime)
{
	player->Update(gameTime);
	player2->Update(gameTime);
}

void Game::Draw(float gameTime)
{
	//Simple RGB value for background so use XRGB instead of ARGB
	gDevice->Clear(D3DCOLOR_XRGB(0, 100, 100));
	gDevice->Begin();

	//Draw logic.
	if (player)
	{
		player->Draw(gameTime);
	}

	if (player2)
	{
		player2->Draw(gameTime);
	}

	gDevice->End();
	gDevice->Present();
}

Game::~Game()
{
	if (player)
	{
		delete player;
		player = 0;
	}

	if (player2)
	{
		delete player2;
		player2 = 0;
	}

	if (gDevice)
	{
		delete gDevice;
		gDevice = 0;
	}
}