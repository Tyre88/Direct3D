#ifndef GAMETIME_H
#define GAMETIME_H

#include <Windows.h>

class GameTime
{
public:
	float elapsedGameTime;
	float totalGameTime;

	bool Initialize();
	void Update();

private:
	LONGLONG start;
	float frequencySeconds;
};

#endif