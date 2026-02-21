#include "Enemy.h"
#include "../../Utility/ResourceManager.h"

#include "DxLib.h"

int Enemy_image;

Enemy::Enemy() : move_animation()
{
    location = Vector2D(0, 0);
    velocity = 0;
    //アニメーション画像の読み込み
    ResourceManager* rm = ResourceManager::GetInstance();
    move_animation = rm->GetImages("Resource/image/Enemy/bear.png", 5, 5, 1, 100, 100);

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
    // 登場位置を右側にセット
    this->location = Vector2D(1000, 400);
    velocity = Vector2D(1, 0);
}

void Enemy::Update(float delta_second)
{
    // アニメーション制御
    AnimeCount(delta_second);

    location += velocity;
    if (location.x > 1240|| location.x<700)
    {
        velocity *= -1;
    }
}

void Enemy::Draw(const Vector2D& screen_offset) const
{
    /*DrawCircle( location.x, location.y, 15, GetColor(255,0,0), TRUE);*/
    DrawRotaGraph(100, 400, 2, 0, image, TRUE);
    __super::Draw(screen_offset);
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
