#include "Block.h"
#include "../../Utility/ResourceManager.h"
#include "../../Utility/Vector2D.h"

#include "DxLib.h"

Block::Block():
    image(),
	start_x(0),
	scroll(0)
{
    image = LoadGraph("Resource/image/Block/snow.png");
}


Block::~Block()
{

}

void Block::Initialize() {

    collision.is_blocking = true;
    collision.object_type = eObjectType::block;
    collision.hit_object_type = { eObjectType::player,
                                  eObjectType::enemy, };

    collision.radius = D_OBJECT_SIZE / 2.0f;

    box_size = Vector2D(32, 32);
}

void Block::Update(float delta_second)
{

    collision.radius = box_size.x / 2;

    collision.point[0] = location + Vector2D(0, -box_size.y / 2 + collision.radius);
    collision.point[1] = location + Vector2D(0, box_size.y / 2 - collision.radius);

    SetScroll(scroll);

	location_x = static_cast<int>(location.x);
    location_y = static_cast<int>(location.y);
}

void Block::Draw(const Vector2D& screen_offset) const
{
    float drawX = location.x + screen_offset.x;
    float drawY = location.y + screen_offset.y;

    // ブロック（足場）画像
    DrawRotaGraph(drawX, drawY, 1.0, 0.0, image, TRUE, 0);

    // 当たり判定可視化
    Vector2D p0 = collision.point[0] + screen_offset;
    Vector2D p1 = collision.point[1] + screen_offset;

    // 上下の円
    DrawCircle(p0.x, p0.y, collision.radius, GetColor(0, 0, 255), FALSE);
    DrawCircle(p1.x, p1.y, collision.radius, GetColor(0, 0, 255), FALSE);

	DrawFormatString(location.x, location.y, GetColor(255, 255, 255), "%d",location_x);
	DrawFormatString(location.x, location.y + 15, GetColor(255, 255, 255), "%d",location_y);
}

void Block::Finalize()
{

}


void Block::OnHitCollision(GameObject* hit_object)
{
    if (hit_object->GetCollision().IsCheckHitTarget(eObjectType::enemy))
    {
        // エネミーに当たったときの処理
    }
    else if (hit_object->GetCollision().IsCheckHitTarget(eObjectType::player))
    {
        // プレイヤーに当たったときの処理
        printfDx("Enemy Hit!\n");
    }
}

const Vector2D& Block::GetLocation() const
{
    return location;
}

//位置情報設定処理
void Block::SetLocation(const Vector2D& pos)
{
    Vector2D center = pos + Vector2D(box_size.x / 2, box_size.y / 2);  //　中心座標に変換する
    GameObject::SetLocation(center); // 親の処理

}

void Block::SetScroll(float scrollX)
{
    scroll = scrollX;
}