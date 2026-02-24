#pragma once

#include "../GameObject.h"
#include <vector>

class Block : public GameObject
{
private:

	int image;
	float start_x;         // 初期位置
	float scroll;          // スクロール値
	int location_x;      // 現在の位置
	int location_y;      // 現在の位置

public:
	Block();
	 ~Block();

	void Initialize() override;
	void Update(float delta_second) override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	// 当たり判定通知処理
	void OnHitCollision(GameObject* hit_object) override;
	//位置情報取得処理
	const Vector2D& GetLocation() const;
	//位置情報設定処理
	void SetLocation(const Vector2D& pos) override;
	void SetScroll(float scrollX);
};
