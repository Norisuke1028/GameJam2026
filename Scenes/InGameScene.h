#pragma once

#include "SceneBase.h"
#include <vector>

class InGameScene : public SceneBase
{
private:
	class Player* player;

	int ch_image;

private:
	eSceneType next_scene; // 遷移先のシーン
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	// 現在のシーンタイプ情報を取得する
	virtual eSceneType GetNowSceneType() const override;
};

