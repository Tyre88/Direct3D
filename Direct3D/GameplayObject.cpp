#include "GameplayObject.h"

GameplayObject::GameplayObject(float x, float y, float rotation, float speed, float maxSpeed)
{
	float twopi = (float)(M_PI * 2);
	position.x = x;
	position.y = y;
	position.z = 0;

	if (rotation > twopi)
	{
		rotation = twopi;
	}

	if (rotation < 0)
	{
		rotation = 0;
	}

	if (speed > maxSpeed)
	{
		speed = maxSpeed;
	}

	if (speed < 0)
	{
		speed = 0;
	}

	this->rotation = rotation;
	this->speed = speed;

	velocity.x = cos(rotation) * speed;
	velocity.y = sin(rotation) * speed;
	velocity.z = 0;

	this->maxSpeed = maxSpeed;
}

bool GameplayObject::Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height)
{
	status = ObjectStatus::Active;

	//Av n�gon anledning s� �r sprite ett objekt :S
	//if (!sprite)
	//{
		sprite = new GameSprite();

		if (!sprite->Initialize(device, file, width, height))
		{
			return false;
		}
	//}

	return true;
}

void GameplayObject::Update(float gameTime)
{
	if (status == ObjectStatus::Active)
	{
		position.x += velocity.x * gameTime;
		position.y += velocity.y * gameTime;
	}
}

void GameplayObject::Draw(float gameTime)
{
	if (sprite)
	{
		sprite->Draw(gameTime, position);
	}
}

ObjectStatus GameplayObject::GetStatus() const
{
	return status;
}

void GameplayObject::SetSpeed(float speed)
{
	if (speed >= 0 && speed <= maxSpeed)
	{
		this->speed = speed;

		velocity.x = cos(rotation) * speed;
		velocity.y = sin(rotation) * speed;
		velocity.z = 0;
	}
}

GameplayObject::~GameplayObject()
{
	if (sprite)
	{
		delete sprite;
		sprite = 0;
	}
}