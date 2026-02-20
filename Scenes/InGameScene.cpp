#include "InGameScene.h"
#include "../StageData.h"
#include "../Utility/InputControl.h"
#include "../Objects/Player/Player.h"
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

	player = CreateObject<Player>(Vector2D(100, 100));

	screen_offset = Vector2D(0, 0);
}

eSceneType InGameScene::Update()
{
	StageData* Stage = StageData::GetInstance();
	Stage->Update();

	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	__super::Update();

	float velocity = player->GetVelocity().x;

	// スクロール条件
	if (player->GetLocation().x >= 1280 / 2 ||
		player->GetLocation().x <= 30)
	{
		screen_offset.x -= velocity;
	}
	else
	{
		velocity = 0;
	}

	// 左端制限
	if (screen_offset.x > 0)
	{
		screen_offset.x = 0;
		velocity = 0;
	}

	// 最後に一度だけ設定（重要）
	Stage->SetVelocity(velocity);

	// リザルト画面に遷移する
	if (pad_input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress)
	{
		return eSceneType::eResult;
	}

	Draw();
	// 親クラスの更新処理を呼び出す
	return __super::Update();
}

//描画処理
void InGameScene::Draw() const
{
	__super::Draw();

	StageData* stage = StageData::GetInstance();
	stage->Load();
	float s_location = stage->GetLocation();

	//デバッグ用
	DrawFormatString(10, 50, GetColor(255, 255, 255),
		"offset.x = %.2f", screen_offset.x);

	DrawFormatString(0, 0, GetColor(255, 255, 255),
		"PlayerLocationX: %.2f", player->GetLocation().x);

	DrawFormatString(0, 20, GetColor(255, 255, 255),
		"PlayerVelocityX: %.2f", player->GetVelocity().x);

	DrawFormatString(0, 40, GetColor(255, 255, 255),
		"PlayerLocationY: %.2f", player->GetLocation().y);


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