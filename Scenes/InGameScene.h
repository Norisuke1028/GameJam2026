#pragma once

#include "SceneBase.h"
#include <vector>

class InGameScene : public SceneBase
{

private:
	class Player* player;
	class Enemy* enemy;

	int background_image;

private:
	eSceneType next_scene; // 遷移先のシーン
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	// 現在のシーンタイプ情報を取得する
	virtual const eSceneType GetNowSceneType() const override;

	const Vector2D& GetScreenOffset() const;

};

