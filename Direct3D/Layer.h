#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Layer
{
public:
	int Layers[50][50];

	Layer();
	Layer(int mapWidth, int mapHeight, int tileWidth, int tileHeight);
	~Layer();

	void LoadLayer(string fileName);

private:
	int _mapWidth;
	int _mapHeight;
	int _tileWidth;
	int _tileHeight;
};
#endif