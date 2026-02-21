#include "Enemy.h"
#include "../../Utility/ResourceManager.h"
#include "../../Utility/Vector2D.h"

#include "DxLib.h"

int Enemy_image;

Enemy::Enemy() : move_animation()
{
    //location = Vector2D(0, 0);
    start_x = 0;
    velocity = 0;
    //アニメーション画像の読み込み
    ResourceManager* rm = ResourceManager::GetInstance();
    move_animation = rm->GetImages("Resource/image/Enemy/bear.png", 2, 2, 1, 200, 200);

    image = move_animation[0];

    //エラーチェック
    if (image == -1)
    {
        throw("エネミーの画像がありません\n");
    }

}


Enemy::~Enemy()
{

}

void Enemy::Initialize() {
    speed = 50.0f;       // 1秒で進む距離
    move_range = 200.0f;  // 左右200px移動

    direction = 1;        // 最初は左へ
}

void Enemy::Update(float delta_second)
{
    // アニメーション制御
    AnimeCount(delta_second);

    // 移動
    location.x += direction * speed * delta_second;

    // 右端
    if (location.x > start_x + move_range)
    {
        location.x = start_x + move_range;
        direction = -1;
    }

    // 左端
    if (location.x < start_x - move_range)
    {
        location.x = start_x - move_range;
        direction = 1;
    }
}

void Enemy::Draw(const Vector2D& screen_offset) const
{
    DrawGraph(
        (int)(location.x + screen_offset.x),
        (int)(location.y + screen_offset.y),
        image,
        TRUE);
}

void Enemy::Finalize()
{

}

void Enemy::AnimeCount(float delta_second)
{
    // 移動中のアニメーション
    animation_time += delta_second;
    if (animation_time >= 0.5f)
    {
        animation_time = 0.0f;
        animation_count++;
        if (animation_count >= 2)
        {
            animation_count = 0;
        }
        // 画像の設定
        image = move_animation[animation_num[animation_count]];
    }
}

const Vector2D& Enemy::GetLocation() const
{
    return location;
}

const Vector2D& Enemy::GetVelocity() const
{
    return velocity;
}
//位置情報設定処理
void Enemy::SetLocation(const Vector2D& pos)
{
    GameObject::SetLocation(pos); // 親の処理
    start_x = pos.x;              // Enemy固有の初期化
}
