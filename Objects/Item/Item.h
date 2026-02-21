#pragma once

#include "../GameObject.h"
#include "../../Utility/InputControl.h"
#include <vector>

class Item : public GameObject
{
private:
	InputControl* input;
private:
	int Animation;
	//アニメーション用
	const int animation_num[2] = { 0,1 };

public:
	Item();
	virtual ~Item();

	void Initialize() override;
	void Update(float delta_second) override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	// 位置情報取得処理
	const Vector2D& GetLocation() const;
	// 位置情報取得処理
	const Vector2D& GetVelocity() const;
};

