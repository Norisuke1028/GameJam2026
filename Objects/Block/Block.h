#pragma once

#include "../GameObject.h"

class BlockBase : public GameObject
{
public:
	// ブロックの画像保存配列
	std::vector<int> block_image;
	int image; // ブロックの画像

public:
	BlockBase();
	virtual ~BlockBase();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screenoffset)const override;
	virtual void Finalize() override;

	virtual void OnHitCollision(GameObject* hit_object) override;
};