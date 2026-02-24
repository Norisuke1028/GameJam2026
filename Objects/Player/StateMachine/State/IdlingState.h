#pragma once
#include "../PlayerStateBase.h"

class IdlingState : public PlayerStateBase
{
private:
	class InputControl* input;  // 入力情報

//private:
//	const int Idling_animation_num[2] = { 0,1 };
//	int Idling_animation_count;
//	float Idling_animation_time;
//
//	int idle_image;  // プレイヤーの画像（Idle）

public:
	IdlingState(class Player* p);
	virtual ~IdlingState();

public:
	virtual void Initialize() override;

	virtual void Update(float delta_second) override;

	virtual void Draw()const override;

	virtual void Finalize() override;

	virtual ePlayerState GetState()const override;
};