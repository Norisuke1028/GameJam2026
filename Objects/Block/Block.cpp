#include "Block.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

BlockBase::BlockBase() :
	block_image(),
	image(0)
{
}

BlockBase::~BlockBase()
{
}

void BlockBase::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	block_image = rm->GetImages("Resources/image/Block/snow.png", 1, 1, 1, 64, 64);

	image = block_image[0];

	box_size = Vector2D(32.0f);

	//ìñÇΩÇËîªíËÇÃê›íË
	collision.is_blocking = true;
	collision.object_type = eObjectType::block;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::enemy);
	collision.radius = D_OBJECT_SIZE / 2.0f;
}

void BlockBase::Update(float delta_second)
{
}

void BlockBase::Draw(const Vector2D& screenoffset) const
{
	__super::Draw(screenoffset);
}

void BlockBase::Finalize()
{
}

void BlockBase::OnHitCollision(GameObject* hit_object)
{
}
