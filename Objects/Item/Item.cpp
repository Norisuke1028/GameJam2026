#include "Item.h"
#include "DxLib.h"

int Item_image;

Item::Item():
	input(nullptr)
{
	location = Vector2D(400, 240);
	velocity = 0;
	Item_image = LoadGraph("Resource/image/Item/Item.png");
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
	DrawRotaGraph(320, 240, 0.5, 0, Item_image, TRUE);
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