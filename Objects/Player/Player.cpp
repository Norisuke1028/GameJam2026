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

void Player::Update(float delta_second)
{
	//カメラ視点の値
	SetScroll(scroll);

	velocity.x = 0;

	if (input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::ePress || 
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::eHeld)
	{
		velocity.x = -0.5;
	}
	if (input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::eHeld)
	{
		velocity.x = 0.5;
	}

	location += velocity;

	// 左端制限
	if (location.x <= 20.0f)
	{
		location.x = 20.0f;
	}

	if (scroll <= -4540.0f)
	{
		// ステージ右端
		if (location.x >= 1270.0f)
		{
			location.x = 1270.0f;
		}
	}
	else
	{
		// 通常（中央固定）
		if (velocity.x > 0 && location.x >= 1280.0f / 2)
		{
			location.x = 1280.0f / 2;
		}
	}
}

void Player::Draw(const Vector2D& screen_offset) const
{
	DrawBox(location.x + 10, location.y + 10,
		location.x - 10, location.y - 10,
		GetColor(255, 255, 255), TRUE);
	
	DrawFormatString(400, 50, GetColor(255, 255, 255), "PlayerLocationY: %f", location.y);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "scroll = %f", scroll);
}

void Player::Finalize()
{
}

void Player::OnHitCollision(const GameObject& hit_object)
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
// カメラ視点の値を受け取る
void Player::SetScroll(float scrollX)
{
	scroll = scrollX;
}

