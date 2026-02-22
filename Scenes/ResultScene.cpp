#include "ResultScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
#include "../Utility/ResourceManager.h"

#include <string>

int Result_image;
int Result_score;
int score = 5000;
int ResultBgmHandle;
bool flag;
float time;

ResultScene::ResultScene() : score_animation()
{
	next_scene = eSceneType::eResult;
	// 画像の読み込み
	Result_image = LoadGraph("Resource/image/Result/result.png");

	ResourceManager* rm = ResourceManager::GetInstance();
	score_animation = rm->GetImages("Resource/image/Result/Score.png", 3, 3, 1, 200, 200);

	Result_score = score_animation[0];

	// BGMの読み込み
	ResultBgmHandle = LoadSoundMem("Resource/sounds/Result/resultBGM.mp3");
}

ResultScene::~ResultScene()
{

}

void ResultScene::Initialize()
{
	printf("リザルト画面");
	flag = FALSE;
	time = 0.0;
}

eSceneType ResultScene::Update(const float& delta_second)
{
	time += delta_second;
	ResultBgm();
	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	// エンドシーンに遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eTitle;
	}

	if (time > 5.0)
	{
		flag = TRUE;
	}
	else
	{

	}

	return eSceneType::eResult;
}

// 描画処理
void ResultScene::Draw() const
{
	DrawGraph(0, 0, Result_image, TRUE);

	//スコアの評価の判定
	if (flag == TRUE)
	{
		if (score > 3000)
		{
			Result_score = score_animation[0];
			DrawGraph(760, 220, Result_score, TRUE);
		}
		else if (score > 1000)
		{
			Result_score = score_animation[1];
			DrawGraph(760, 220, Result_score, TRUE);
		}
		else
		{
			Result_score = score_animation[2];
			DrawGraph(760, 220, Result_score, TRUE);
		}
	}
	else
	{
		Result_score = score_animation[(int)(rand() * (3 - 1 + 1.0) / (1.0 + RAND_MAX))];
		DrawGraph(760, 220, Result_score, TRUE);
	}
}

void ResultScene::Finalize()
{
	// リザルトのBGMを停止する処理
	StopSoundMem(ResultBgmHandle);
}

const eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}

void ResultScene::ResultBgm()
{
	// タイトルのBGMを再生する処理
	if (CheckSoundMem(ResultBgmHandle) == 0)
	{
		PlaySoundMem(ResultBgmHandle, DX_PLAYTYPE_LOOP, TRUE);
		CheckSoundMem(ResultBgmHandle);
	}
}
