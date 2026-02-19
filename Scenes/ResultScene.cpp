#include "ResultScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

ResultScene::ResultScene()
{
	next_scene = eSceneType::eResult;
}

ResultScene::~ResultScene()
{

}

void ResultScene::Initialize()
{
	printf("リザルト画面");
}

eSceneType ResultScene::Update()
{
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// タイトル画面に遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eTitle;
	}

	Draw();
	return eSceneType::eResult;
}

// 描画処理
void ResultScene::Draw() const
{
	DrawFormatString(120, 140, GetColor(255, 255, 0), "リザルト画面");

}

void ResultScene::Finalize()
{

}

eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}