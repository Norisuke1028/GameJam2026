#include "InGameScene.h"
#include "DxLib.h"

InGameScene::InGameScene()
{
	next_scene = eSceneType::eInGame;
}

InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{

}

eSceneType InGameScene::Update()
{
	return eSceneType::eInGame;
}

//ï`âÊèàóù
void InGameScene::Draw() const
{

}

void InGameScene::Finalize()
{

}

eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}