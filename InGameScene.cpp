#include "InGameScene.h"
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
}

eSceneType InGameScene::Update()
{
	Draw();
	return eSceneType::eInGame;
}

//•`‰æˆ—
void InGameScene::Draw() const
{
	// ƒJ[ƒ\ƒ‹‰æ‘œ‚Ì•`‰æ
	DrawRotaGraph(320, 240, 0.25, 0, ch_image, TRUE, FALSE);
}

void InGameScene::Finalize()
{

}

eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}