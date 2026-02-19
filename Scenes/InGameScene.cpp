#include "InGameScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

InGameScene::InGameScene()
{
	next_scene = eSceneType::eInGame;
}

InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{
	ch_image = LoadGraph("Resource/b.png");
}

eSceneType InGameScene::Update()
{
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// リザルト画面に遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eResult;
	}

	Draw();
	return eSceneType::eInGame;
}

//描画処理
void InGameScene::Draw() const
{
	// カーソル画像の描画
	DrawRotaGraph(320, 240, 0.25, 0, ch_image, TRUE, FALSE);
	DrawFormatString(120, 140, GetColor(255, 255, 0), "インゲームシーンです");
}

void InGameScene::Finalize()
{

}

eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}