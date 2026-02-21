#include "Title.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include <string>

int cursor_number = 0;
int a = 0;
int title_image;
int start_image;
int shuryo_image;
int help_image;
int cursor_image;
int start1_image;
int shuryo1_image;
int help1_image;

TitleScene::TitleScene()
{
	next_scene = eSceneType::eTitle;
	// 画像の読み込み
	title_image = LoadGraph("Resource/image/Title/title.png");
	start_image = LoadGraph("Resource/image/Title/startmae.png");
	shuryo_image = LoadGraph("Resource/image/Title/shuryoumae.png");
	help_image = LoadGraph("Resource/image/Title/helpmae.png");

	cursor_image = LoadGraph("Resource/image/Title/yajirusi.png");

	start1_image = LoadGraph("Resource/image/Title/startgo.png");
	shuryo1_image = LoadGraph("Resource/image/Title/shuryougo.png");
	help1_image = LoadGraph("Resource/image/Title/helpato.png");
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

	// カーソルの移動
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

	// 決定する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_A) == ePadInputState::ePress)
	{
		a += 1;
		// カーソルの位置に応じて遷移先のシーンを変更する
		switch (cursor_number)
		{
		case 0:
			return eSceneType::eInGame;
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
	DrawGraph(0, 0, title_image, TRUE);
	DrawGraph(90, 240, start_image, TRUE);
	DrawGraph(115, 350, help_image, TRUE);
	DrawGraph(90, 330, shuryo_image, TRUE);
	
	int cursor = cursor_number * 100; // カーソルの位置を計算
	DrawGraph(0, 300 + cursor, cursor_image, TRUE); // カーソルを描画

	if (cursor_number == 0 /*&& a == 1*/)
	{
		DrawGraph(90, 240, start1_image, TRUE);
		
	}
	if (cursor_number == 1 /*&& a == 1*/)
	{
		DrawGraph(115, 350, help1_image, TRUE);
		
	}
	if (cursor_number == 2 /*&& a == 1*/)
	{
		DrawGraph(90, 330, shuryo1_image, TRUE);
		
	}
	//switch (cursor_number)
	//{
	//case 0:
	//	DrawGraph(90, 240, start1_image, TRUE);
	//	break;
	//case 1:
	//	DrawGraph(115, 350, help1_image, TRUE);
	//	break;
	//case 2:
	//	DrawGraph(90, 330, shuryo1_image, TRUE);
	//	break;
	//}

	//if (a == 1)
	//{
	//	
	//	WaitTimer(1000); // 1秒待機
	//	a--;
	//}
}

void TitleScene::Finalize()
{

}

const eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}