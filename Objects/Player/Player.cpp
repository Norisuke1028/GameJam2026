#include "Player.h"
#include "DxLib.h"

Player::Player() :
	input(nullptr),
	ingame_s(nullptr),
	gravity(0.0f),
	scroll(0.0f),
	is_on_ground(false),
	state(nullptr),
	next_state(ePlayerState::NONE)
{
	
}

Player::~Player()
{

}

void Player::Initialize()
{
	input = InputControl::GetInstance();
	ResourceManager* rm = ResourceManager::GetInstance();

	collision.is_blocking = true;
	collision.object_type = eObjectType::player;
	collision.hit_object_type = { eObjectType::enemy,
								  eObjectType::block,
								  eObjectType::item,
								  eObjectType::gool };
	
	collision.radius = D_OBJECT_SIZE / 2.0f;

	z_layer = 5;

	mobility = eMobilityType::Movable;
	state = PlayerStateFactory::Get(*this, ePlayerState::IDLE);
	next_state = ePlayerState::NONE;

	velocity = Vector2D(0.0f, 0.0f);


	box_size = Vector2D(32.0f, 32.0f);
}

void Player::Update(float delta_second)
{
	// ----- カメラ視点の値 ----- //
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

	// 重力の適用
	velocity.y += GRAVITY * delta_second;

	location += velocity * delta_second;

	if(location.y >= 600.0f)
	{
		location.y = 600.0f;
		is_on_ground = true;
	}
	else
	{
		is_on_ground = false;
	}
}

void Player::Draw(const Vector2D& screen_offset) const
{
	DrawBox(location.x + 10, location.y + 10,
		location.x - 10, location.y - 10,
		GetColor(255, 255, 255), TRUE);

	DrawBox(location.x + box_size.x / 2, location.y + box_size.y / 2,
		location.x - box_size.x / 2, location.y - box_size.y / 2,
		GetColor(255, 0, 0), FALSE);
	
	DrawFormatString(400, 50, GetColor(255, 255, 255), "PlayerLocationY: %f", location.y);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "scroll = %f", scroll);
}

void Player::Finalize()
{
}

void Player::Movement(float delta_second)
{
}

void Player::OnHitCollision(const GameObject* hit_object)
{
	if(hit_object->GetCollision().IsCheckHitTarget(eObjectType::block))
	{
		// ブロックに当たったときの処理
	}
	else if(hit_object->GetCollision().IsCheckHitTarget(eObjectType::enemy))
	{
		// 敵に当たったときの処理
	}
	else if(hit_object->GetCollision().IsCheckHitTarget(eObjectType::item))
	{
		// アイテムに当たったときの処理
	}
	else if(hit_object->GetCollision().IsCheckHitTarget(eObjectType::gool))
	{
		// ゴールに当たったときの処理
	}
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

