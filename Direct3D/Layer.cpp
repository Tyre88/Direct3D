#include "Layer.h"

Layer::Layer(){}
Layer::Layer(int mapWidth, int mapHeight, int tileWidth, int tileHeight)
{
	if (mapWidth <= 50)
	{
		_mapWidth = mapWidth;
	}
	else
	{
		_mapWidth = 50;
	}

	if (mapHeight <= 50)
	{
		_mapHeight = mapHeight;
	}
	else
	{
		_mapHeight = 50;
	}

	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
}

void Layer::LoadLayer(string fileName)
{
	ifstream objreader(fileName);

	if (objreader.is_open())
	{
		string str;
		int lineNumber = 1;
		int x = 0;
		int y = 0;
		while (getline(objreader, str))
		{
			if (lineNumber % _mapHeight != 0)
			{
				istringstream (str) >> Layers[x][y];
				y++;
			}
			else
			{
				y = 0;
				x++;
			}

			lineNumber++;
		}
	}
	else
	{
		cout << "There was an error reading the layer";
	}

	objreader.close();
}

Layer::~Layer()
{

}