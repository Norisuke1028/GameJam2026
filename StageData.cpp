#include "StageData.h"
#include "DxLib.h"

#include <string>

StageData* StageData::instance = nullptr;

StageData* StageData::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new StageData();
    }
    return instance;
}

StageData::StageData() : s_location()
{

}

StageData::~StageData()
{

}

void StageData::Initialize()
{

}

void StageData::Update()
{
	s_location += velocity.x;
}

void StageData::Draw(const Vector2D& screen_offset) const
{
	DrawFormatString(120, 140, GetColor(255, 255, 0), "%d",location);
}

void StageData::Finalize()
{

}
float StageData::GetLocation()const
{
	return s_location;
}

Vector2D StageData::GetVelocity()
{
	return velocity;
}

void StageData::SetVelocity(float velo)
{
	velocity.x -= velo;
}