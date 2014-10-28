#ifndef GAME_H
#define GAME_H

#include "GraphicsDevice.h"
#include "GameplayObject.h"
#include "GameTime.h"

class Game
{
public:
	Game();
	~Game();

	bool Initialize(HWND hWnd);
	void Run();
	void Update(float gameTime);
	void Draw(float gameTime);

private:
	GraphicsDevice *gDevice;
	GameplayObject *player;
	GameplayObject *player2;

	GameTime *gameTime;
};

#endif