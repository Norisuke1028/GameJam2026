#include "InGameScene.h"
#include "../StageData.h"
#include "../Utility/InputControl.h"
#include "../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include "DxLib.h"

#include <string>

InGameScene::InGameScene()
	: player(nullptr)
	, enemy(nullptr)
	, background_image(0)
	, next_scene(eSceneType::eInGame)
{
}

InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{
	background_image = LoadGraph("Resource/image/sky.png");

	player = CreateObject<Player>(Vector2D(100, 100));

	stage_data.Load();

	/*const std::vector<Vector2D>& spawns =
		stage_data.GetEnemySpawnPositions();*/

	//printfDx("spawn size = %d\n", spawns.size());

	//エネミーの生成
	for (const Vector2D& pos : stage_data.GetEnemySpawnPositions())
	{
		CreateObject<Enemy>(pos);
	}

	//アイテムの生成

	screen_offset = Vector2D(0, 0);
}

eSceneType InGameScene::Update(const float& delta_second)
{
	StageData* Stage = StageData::GetInstance();
	Stage->Update(delta_second);

	// 入力情報を取得
	InputControl* pad_input = InputControl::GetInstance();

	player->SetScroll(screen_offset.x);
	__super::Update(delta_second);

	float velocity = player->GetVelocity().x * delta_second;

	// スクロール条件
	if (player->GetLocation().x >= 1280 / 2 ||
		player->GetLocation().x <= 30)
	{
		// プレイヤーの加速度分スクロールする
		screen_offset.x -= velocity;
	}
	else
	{
		// スクロールできなくさせる
		velocity = 0;
	}

	// 左端制限
	if (screen_offset.x > 0)
	{
		screen_offset.x = 0;
		velocity = 0;
	}

	// 右端制限
	if (screen_offset.x < -4540)
	{
		screen_offset.x = -4540;
		velocity = 0;
	}

	// 最後に一度だけ設定
	Stage->SetVelocity(velocity);

	//// リザルト画面に遷移する
	if (screen_offset.x > -4540 && player->GetLocation().x >850)
	{
		return eSceneType::eResult;
	}

	Draw();

	// 親クラスの更新処理を呼び出す
	return __super::Update(delta_second);
}

//描画処理
void InGameScene::Draw() const
{
	DrawGraph(0,0,background_image,true);
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

	__super::Draw();
}

void InGameScene::Finalize()
{

}

const eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}

//カメラ視点の値を取得する
const Vector2D& InGameScene::GetScreenOffset() const
{
	return screen_offset;
}