#include "Item.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/Vector2D.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

//int item_image;

Item::Item():
	input(nullptr)
{
	location = Vector2D(400, 240);
	velocity = 0;

	start_x = 0;
	velocity = 0;

	ResourceManager* rm = ResourceManager::GetInstance();
	item_animation_move = rm->GetImages("Resource/image/Item/Item.png", 3, 3, 1, 32, 32);
	item_image = item_animation_move[0];
	/*item_image = LoadGraph("Resource/image/Item/Item.png");*/
}

Item::~Item()
{

}

void Item::Initialize()
{
	input = InputControl::GetInstance();
	collision.is_blocking = false;
	collision.object_type = eObjectType::item;
	collision.hit_object_type = { eObjectType::player };

	collision.radius = D_OBJECT_SIZE / 2.0f;

	z_layer = 5;
	box_size = Vector2D(32, 32);
}

void Item::Update(float delta_second)
{
	AnimeCount(delta_second);
}

void Item::Draw(const Vector2D& screen_offset) const
{
	float drawX = location.x + screen_offset.x;
	float drawY = location.y + screen_offset.y;

	int width, height;
	GetGraphSize(item_image, &width, &height);

	DrawRotaGraph(drawX, drawY, 0.1, 0.0, item_image, TRUE);
}

void Item::Finalize()
{

}

void Item::AnimeCount(float delta_second)
{
	// 画像の設定
	item_animation_time += delta_second;
	if (item_animation_time >= 0.5f)
	{
		item_animation_time = 0.0f;
		item_animation_count++;
		if (item_animation_count >= 2)
		{
			item_animation_count = 0;
		}
	}
	item_image = item_animation_move[item_animation_num[item_animation_count]];
}

void Item::OnHitCollision(const GameObject* hit_object)
{
	if (hit_object->GetCollision().IsCheckHitTarget(eObjectType::player))
	{
		// プレイヤーに当たったときの処理
		printfDx("Player Hit!\n");
		delete_flag = true;
	}
}

const Vector2D& Item::GetLocation() const
{
	return location;
}

const Vector2D& Item::GetVelocity() const
{
	return velocity;
}

// 位置情報設定処理
void Item::SetLocation(const Vector2D& pos)
{
	GameObject::SetLocation(pos);
	start_x = pos.x;
}