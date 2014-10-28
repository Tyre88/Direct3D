#ifndef GAMEPLAYOBJECT_H
#define GAMEPLAYOBJECT_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "GameSprite.h"
#include <string>

enum class ObjectStatus { Active, Dying, Dead };

class GameplayObject
{
public:
	GameplayObject(float x, float y, float rotation, float speed, float maxSpeed);
	~GameplayObject();

	virtual bool Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height);
	virtual void Update(float gameTime);
	virtual void Draw(float gameTime);

	ObjectStatus GetStatus() const;

	void SetSpeed(float speed);

protected:
	//Informational data
	std::string Name;
	std::string Description;

	//Physics data
	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
	float rotation;
	float speed;

private:
	ObjectStatus status;

	GameSprite *sprite;

	float maxSpeed;
};

#endif