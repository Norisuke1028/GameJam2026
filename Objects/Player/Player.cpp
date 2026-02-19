#include "Player.h"
#include "DxLib.h"

Player::Player():
	input(nullptr)
{
	location = Vector2D(200, 240);
	velocity = 0;
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
	if (input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::ePress || 
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::eHeld)
	{
		location.x -= 5;
	}
	if (input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::eHeld)
	{
		location.x += 5;
	}

	location += velocity;
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

