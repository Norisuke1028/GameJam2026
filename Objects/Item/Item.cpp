#include "Item.h"
#include "DxLib.h"

int Item_image[3];
int animation = 0;

Item::Item():
	input(nullptr)
{
	location = Vector2D(400, 240);
	velocity = 0;
	Item_image[0] = LoadGraph("Resource/image/Item/Item.png");
	Item_image[1] = LoadGraph("Resource/image/Item/Item1.png");
	Item_image[2] = LoadGraph("Resource/image/Item/Item2.png");
}

Item::~Item()
{

}

void Item::Initialize()
{
	input = InputControl::GetInstance();
}

void Item::Update()
{
	
}

void Item::Draw(const Vector2D& screen_offset) const
{
	/*DrawCircle(320, 240, 15, GetColor(255, 255, 0), TRUE);*/
	/*DrawRotaGraph(320, 240, 0.5, 0, Item_image[0], TRUE);*/
	animation = (animation + 1) % 2;
	DrawGraph(320, 240, Item_image[animation], TRUE);
}

void Item::Finalize()
{

}

const Vector2D& Item::GetLocation() const
{
	return location;
}

const Vector2D& Item::GetVelocity() const
{
	return velocity;
}