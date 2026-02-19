#include "Player.h"
#include "DxLib.h"

Player::Player()
{
	location = Vector2D(200, 240);
}

Player::~Player()
{

}

void Player::Initialize()
{

}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_A) == true)
	{
		location += -5;
	}
	if (CheckHitKey(KEY_INPUT_D) == true)
	{
		location += 5;
	}
}

void Player::Draw() const
{
	DrawBox(location.x + 10, location.y + 10,
		location.x - 10, location.y - 10,
		GetColor(255, 255, 255), TRUE);

}

void Player::Finalize()
{
}

