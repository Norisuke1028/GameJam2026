#pragma once

#include "../GameObject.h"
#include <vector>



class Enemy : public GameObject
{
public:
	Enemy();
	virtual ~Enemy();

	void Initialize() override;
	void Update() override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	//ˆÊ’uî•ñæ“¾ˆ—
	const Vector2D& GetLocation() const;
	//ˆÊ’uî•ñæ“¾ˆ—
	const Vector2D& GetVelocity() const;

};
