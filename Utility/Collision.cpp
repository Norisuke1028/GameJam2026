#include "Collision.h"
#include <math.h>

CapsuleCollision::CapsuleCollision() :
	is_blocking(false),
	object_type(eObjectType::none),
	hit_object_type(),
	radius(0.0f, 0.0f)
{
	point[0] = Vector2D(0.0f, 0.0f);
	point[1] = Vector2D(0.0f, 0.0f);
}

CapsuleCollision::~CapsuleCollision()
{

}

bool CapsuleCollision::IsCheckHitTarget(eObjectType hit_object) const
{
	// 適用するオブジェクトタイプなら true
	for (eObjectType type : hit_object_type)
	{
		if (type == hit_object)
		{
			return true;
		}
	}

	return false;
}

bool IsCheckCollision(const CircleCollision& c1, const CircleCollision& c2)
{
	// 2点間の距離と長さ
	Vector2D diff = (c1.point - c2.point);
}

bool IsCheckCollision(const CapsuleCollision& c1, const CircleCollision& c2)
{

}
bool IsCheckCollision(const CapsuleCollision& c1, const CapsuleCollision& c2)
{

}