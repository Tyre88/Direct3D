#include "GameTime.h"

bool GameTime::Initialize()
{
	LARGE_INTEGER i;

	//Get frequency from counter. The frequency can't change wile the system is running.
	if (!QueryPerformanceFrequency(&i))
	{
		return false;
	}

	//Gives us the number of tics per second.
	frequencySeconds = (float)(i.QuadPart);

	//Gets the current value of the counter.
	QueryPerformanceCounter(&i);
	start = i.QuadPart;
	totalGameTime = 0;
	elapsedGameTime = 0;

	return true;
}

void GameTime::Update()
{
	LARGE_INTEGER i;

	QueryPerformanceCounter(&i);
	elapsedGameTime = (float)(i.QuadPart - start) / frequencySeconds;

	start = i.QuadPart;
	totalGameTime += elapsedGameTime;
}