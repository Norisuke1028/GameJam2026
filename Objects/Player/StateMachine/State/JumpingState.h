#pragma once
#include "../PlayerStateBase.h"

class JumpingState : public PlayerStateBase
{
public:
	JumpingState(class Player* p);
	~JumpingState();

public:
	virtual void Initialize() override;

	virtual void Update(float delta_second) override;

	virtual void Draw()const override;

	virtual void Finalize() override;

	virtual ePlayerState GetState()const override;
};