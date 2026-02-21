#include "Item.h"
#include "DxLib.h"


Item::Item():
	input(nullptr)
{
	location = Vector2D(400, 240);
	velocity = 0;
}

Item::~Item()
{

}

void Item::Initialize()
{
	input = InputControl::GetInstance();
}

void Item::Update(float delta_second)
{
	Animation;
}

void Item::Draw(const Vector2D& screen_offset) const
{
	
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