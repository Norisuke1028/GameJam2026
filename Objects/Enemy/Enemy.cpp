#include "Enemy.h"
#include "../../Utility/ResourceManager.h"
#include "../../Utility/Vector2D.h"

#include "DxLib.h"

int Enemy_image;

Enemy::Enemy() : move_animation(), direction(-1)
{
    //location = Vector2D(0, 0);
    start_x = 0;
    velocity = 0;
    //アニメーション画像の読み込み
    ResourceManager* rm = ResourceManager::GetInstance();
    move_animation = rm->GetImages("Resource/image/Enemy/bear.png", 2, 2, 1, 200, 200);
    image = move_animation[0];
    die_image = LoadGraph("Resource/image/Enemy/bear_down.png");
    //image = walk_image;
}


Enemy::~Enemy()
{

}

void Enemy::Initialize() {
    speed = 50.0f;       // 1秒で進む距離
    move_range = 200.0f;  // 左右200px移動

    direction = -1;        // 最初は左へ
    enemy_state = EnemyState::WALK;
    collision.is_blocking = true;
    collision.object_type = eObjectType::enemy;
    collision.hit_object_type = { eObjectType::player,
                                  eObjectType::block,};

    collision.radius = D_OBJECT_SIZE / 2.0f;

    z_layer = 5;
    box_size = Vector2D(110, 130);
}

void Enemy::Update(float delta_second)
{
    switch (enemy_state)
    {
    case WALK: 
        // アニメーション制御
        AnimeCount(delta_second);

        // 移動
        location.x += direction * speed * delta_second;

        // 右端
        if (location.x >= start_x + move_range)
        {
            location.x = start_x + move_range;
            direction = -1;
        }

        // 左端
        if (location.x <= start_x - move_range)
        {
            location.x = start_x - move_range;
            direction = 1;
        }
        break;
    case DIE:
        image = die_image;
        break;
    default:
        break;
    }

    collision.point[0] = location;
    collision.point[1] = location;
}

void Enemy::Draw(const Vector2D& screen_offset) const
{
    float drawX = location.x + screen_offset.x;
    float drawY = location.y + screen_offset.y;

    int width, height;
    GetGraphSize(image, &width, &height);

    // エネミー画像
    DrawRotaGraph(drawX, drawY, 1.0, 0.0, image, TRUE, direction == 1);

    // 当たり判定（矩形）
    DrawBox(
        drawX - box_size.x / 2,
        drawY - box_size.y / 2,
        drawX + box_size.x / 2,
        drawY + box_size.y / 2,
        GetColor(255, 0, 0),
        FALSE);

    // 中心点
    DrawCircle(drawX, drawY, 3, GetColor(0, 255, 0), TRUE);

    DrawFormatString(900, 200,
        GetColor(255, 255, 255),
        "start_x=%.1f location=%.1f",
        start_x, location.x);
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

void Enemy::OnHitCollision(const GameObject* hit_object)
{
    if (hit_object->GetCollision().IsCheckHitTarget(eObjectType::block))
    {
        // ブロックに当たったときの処理
    }
    else if (hit_object->GetCollision().IsCheckHitTarget(eObjectType::player))
    {
        // プレイヤーに当たったときの処理
        printfDx("Enemy Hit!\n");
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
