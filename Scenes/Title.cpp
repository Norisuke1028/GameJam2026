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

eSceneType TitleScene::Update()
{
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// インゲームシーンに遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eInGame;
	}

	// 上入力でカーソルを上に
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_DPAD_UP) == ePadInputState::ePress)
	{
		cursor_number--; // カーソルを上に移動
		if (cursor_number < 0)
		{
			cursor_number = 2; // カーソルを末尾に移動
		}
	}

	// 下入力でカーソルを下に
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_DPAD_DOWN) == ePadInputState::ePress)
	{
		cursor_number++; // カーソルを下に移動
		if (cursor_number > 2)
		{
			cursor_number = 0; // カーソルを最初に移動
		}
	}

	if (pad_input->GetButtonInputState(XINPUT_BUTTON_A) == ePadInputState::ePress)
	{
		// Aボタン入力で項目を選択
		switch (cursor_number)
		{
		case 0:
			return eSceneType::eInGame; // ゲーム開始
		case 1:
			return eSceneType::eResult; // リザルト画面
		case 2:
			return eSceneType::eEnd; // エンドシーン
		}
	}
	Draw();
	return eSceneType::eTitle;
}

//描画処理
void TitleScene::Draw() const
{
	// タイトル画面の項目の描画
	DrawFormatString(120, 140, GetColor(255, 255, 0), "タイトルシーンです");
	DrawFormatString(560, 240, GetColor(255, 255, 0), "ゲーム名");
	DrawFormatString(560, 440, GetColor(255, 255, 0), "ゲームスタート");
	DrawFormatString(560, 460, GetColor(255, 255, 0), "ランキング");
	DrawFormatString(560, 480, GetColor(255, 255, 0), "ゲーム終了");
	
	int cursor = cursor_number * 20; // 行ごとのオフセット
	DrawString(540, 440 + cursor, "→", GetColor(255, 255, 0)); // 矢印の描画
}

void TitleScene::Finalize()
{

}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}