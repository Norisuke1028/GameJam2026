#include "Title.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

int cursor_number = 0;
int title_image;
int start_image;
int shuryo_image;
int cursor_image;

TitleScene::TitleScene()
{
	next_scene = eSceneType::eTitle;
	title_image = LoadGraph("Resource/image/Title/title.png");
	start_image = LoadGraph("Resource/image/Title/startmae.png");
	shuryo_image = LoadGraph("Resource/image/Title/shuryoumae.png");
	cursor_image = LoadGraph("Resource/image/Title/yajirusi.png");
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
	/*DrawFormatString(120, 140, GetColor(255, 255, 0), "タイトルシーンです");*/
	/*DrawFormatString(560, 240, GetColor(255, 255, 0), "ゲーム名");*/
	/*DrawFormatString(60, 440, GetColor(255, 255, 0), "ゲームスタート");*/
	/*DrawFormatString(60, 460, GetColor(255, 255, 0), "ヘルプ");
	DrawFormatString(60, 480, GetColor(255, 255, 0), "終了");*/
	DrawGraph(0, 0, title_image, TRUE);
	DrawGraph(90, 240, start_image, TRUE);
	DrawGraph(90, 330, shuryo_image, TRUE);
	
	/*DrawFormatString(540, 440, GetColor(255, 255, 0), "→");*/
	int cursor = cursor_number * 100;
	/*DrawString(40, 440 + cursor, "→", GetColor(255, 255, 0));*/
	DrawGraph(0, 300 + cursor, cursor_image, TRUE);
}

void TitleScene::Finalize()
{

}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}