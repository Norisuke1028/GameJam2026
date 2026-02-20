#include "Enemy.h"
#include "DxLib.h"


Enemy::Enemy() 
{
    location = Vector2D(0, 0);
    velocity = 0;
}

Enemy::~Enemy()
{

}

void Enemy::Initialize() {
    // 登場位置を右側にセット
    this->location = Vector2D(1000, 400);
    velocity = Vector2D(1, 0);
}

void Enemy::Update()
{
    location += velocity;
    if (location.x > 1280|| location.x<700)
    {
        velocity *= -1;
    }
}

void Enemy::Draw(const Vector2D& screen_offset) const
{
    DrawCircle( location.x, location.y, 15, GetColor(255,0,0), TRUE);
}

void Enemy::Finalize()
{

}

const Vector2D& Enemy::GetLocation() const
{
    return location;
}

const Vector2D& Enemy::GetVelocity() const
{
    return velocity;
}
