#pragma once

#include "Objects/GameObject.h"
#include "Scenes/SceneBase.h"
#include <vector>
#include <map>

#include "Utility/Vector2D.h"

/// <summary>
/// 隣接情報のキー
/// </summary>
enum eAdjacentDirection : unsigned char
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

class StageData : public GameObject
{
private:
	static StageData* instance;


private:
	StageData() = default;

	// コピーガード
	StageData(const StageData&) = delete;
	StageData& operator = (const StageData&) = delete;
	// ~コピーガード

public:
	static StageData* GetInstance();

	float s_location;

	~StageData();

public:

// ステージデータを読み込む
	void Load();

	void Initialize() override;
	void Update(float delta_second) override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	//位置情報取得処理
	float GetLocation() const;
	Vector2D GetVelocity();
	void SetVelocity(float velo);
};

