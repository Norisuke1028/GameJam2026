#include "Player.h"
#include "DxLib.h"

Player::Player() :
	input(nullptr)
{
	
}

Player::~Player()
{

}

void Player::Initialize()
{
	input = InputControl::GetInstance();
}

void Player::Update()
{
	velocity.x = 0;

	if (input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::ePress || 
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::eHeld)
	{
		velocity.x = -5;
	}
	if (input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::eHeld)
	{
		velocity.x = 5;
	}

	location += velocity;

	if (location.x >= 1280.0f / 2 && velocity.x > 0)
	{
		location.x = 1280.0f / 2;
	}

	if (location.x <= 20.0f)
	{
		location.x = 20.0f;
	}
	
}

void Player::Draw(const Vector2D& screen_offset) const
{
	DrawBox(location.x + 10, location.y + 10,
		location.x - 10, location.y - 10,
		GetColor(255, 255, 255), TRUE);
	
	DrawFormatString(400, 50, GetColor(255, 255, 255), "PlayerLocationY: %f", location.y);
}

void Player::Finalize()
{
}

const Vector2D& Player::GetLocation() const
{
	return location;
}

const Vector2D& Player::GetVelocity() const
{
	return velocity;
}

