#include "RollingState.h"

#include "DxLib.h"
#include "../PlayerStateBase.h"

RollingState::RollingState(class Player* p) :
	PlayerStateBase(p)
{
}

RollingState::~RollingState()
{
}

void RollingState::Initialize()
{
}

void RollingState::Update(float delta_second)
{
}

void RollingState::Draw() const
{
}

void RollingState::Finalize()
{
}

ePlayerState RollingState::GetState() const
{
	return ePlayerState::ROLL;
}
