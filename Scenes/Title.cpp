#include "Title.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

int cursor_number = 0;

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

eSceneType TitleScene::Update(const float& delta_second)
{
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// インゲームシーンに遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eInGame;
	}

	if (pad_input->GetButtonInputState(XINPUT_BUTTON_DPAD_UP) == ePadInputState::ePress)
	{
		cursor_number--;
		if (cursor_number < 0)
		{
			cursor_number = 2;
		}
	}
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_DPAD_DOWN) == ePadInputState::ePress)
	{
		cursor_number++;
		if (cursor_number > 2)
		{
			cursor_number = 0;
		}
	}

	if (pad_input->GetButtonInputState(XINPUT_BUTTON_A) == ePadInputState::ePress)
	{
		switch (cursor_number)
		{
		case 0:
			return eSceneType::eTitle;
		case 1:
			return eSceneType::eHelp;
		case 2:
			return eSceneType::eEnd;
		}
	}
	Draw();
	return eSceneType::eTitle;
}

//描画処理
void TitleScene::Draw() const
{
	DrawFormatString(120, 140, GetColor(255, 255, 0), "タイトルシーンです");
	DrawFormatString(560, 240, GetColor(255, 255, 0), "ゲーム名");
	DrawFormatString(560, 440, GetColor(255, 255, 0), "ゲームスタート");
	DrawFormatString(560, 460, GetColor(255, 255, 0), "ヘルプ");
	DrawFormatString(560, 480, GetColor(255, 255, 0), "ゲーム終了");
	DrawFormatString(540, 440, GetColor(255, 255, 0), "→");
}

void TitleScene::Finalize()
{

}

const eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}