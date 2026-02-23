#pragma once
#include "../PlayerStateBase.h"

class IdlingState : public PlayerStateBase
{
private:
	class InputControl* input;  // 入力情報

	// 画像配列 ： 今後、プレイヤーの状態に応じて画像を切り替えるために使用
	std::vector<int> player_normal_img;

public:
	IdlingState(class Player* p);
	virtual ~IdlingState();

public:
	virtual void Initialize() override;

	virtual void Update(float delta_second) override;

	virtual void Draw()const override;

	virtual void Finalize() override;

	virtual void Animation(float delta_second) override;

	virtual ePlayerState GetState()const override;
};