#pragma once

#include "SceneBase.h"
#include <vector>

class ResultScene : public SceneBase
{

private:
	eSceneType next_scene; // 遷移先のシーン
private:
	std::vector<int> score_animation;   //スコアのアニメーション
	
public:

	ResultScene();
	virtual ~ResultScene();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	// 現在のシーンタイプ情報を取得する
	virtual const eSceneType GetNowSceneType() const override;


};

