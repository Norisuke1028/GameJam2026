#include "Title.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

TitleScene::TitleScene()
{
	next_scene = eSceneType::eTitle;
}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	printf("タイトルシーンです");
}

eSceneType TitleScene::Update()
{
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// インゲームシーンに遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eInGame;
	}

	Draw();
	return eSceneType::eTitle;
}

//描画処理
void TitleScene::Draw() const
{
	DrawFormatString(120, 140, GetColor(255, 255, 0), "タイトルシーンです");
	
}

void TitleScene::Finalize()
{

}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}