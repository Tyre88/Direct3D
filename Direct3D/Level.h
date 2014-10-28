#ifndef LEVEL_H
#define LEVEL_H

#include "Layer.h"

class Level
{
public:
	int MapHeight;
	int MapWidth;
	int TileHeight;
	int TileWidth;

private:
	Layer *TileLayer1;
	Layer *TileLayer2;
	Layer *SolidLayer;
};

#endif