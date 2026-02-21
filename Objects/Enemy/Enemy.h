#pragma once

#include "../GameObject.h"
#include <vector>



class Enemy : public GameObject
{
private:
	std::vector<int> move_animation;   //移動のアニメーション

	//アニメーション用
	const int animation_num[2] = { 0,1 };
	int animation_count;
	float animation_time;

	int image;

public:
	Enemy();
	virtual ~Enemy();

	void Initialize() override;
	void Update(float delta_second) override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	void AnimeCount(float delta_second);

	//位置情報取得処理
	const Vector2D& GetLocation() const;
	//位置情報取得処理
	const Vector2D& GetVelocity() const;

};
