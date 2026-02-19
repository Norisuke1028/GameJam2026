#include "EndScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

EndScene::EndScene()
{
	next_scene = eSceneType::eEnd;
}

EndScene::~EndScene()
{

}

void EndScene::Initialize()
{
	printf("エンドシーン");
}

eSceneType EndScene::Update()
{
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// タイトル画面に遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eTitle;
	}

	Draw();
	return eSceneType::eEnd;
}

// 描画処理
void EndScene::Draw() const
{
	DrawFormatString(120, 140, GetColor(255, 255, 0), "エンドシーン");

}

void EndScene::Finalize()
{

}

eSceneType EndScene::GetNowSceneType() const
{
	return eSceneType::eEnd;
}