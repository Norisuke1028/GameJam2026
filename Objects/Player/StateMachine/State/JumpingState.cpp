#include "JumpingState.h"

#include "DxLib.h"
#include "../PlayerStateBase.h"

JumpingState::JumpingState(class Player* p) :
	PlayerStateBase(p)
{
}

JumpingState::~JumpingState()
{
}

void JumpingState::Initialize()
{
}

void JumpingState::Update(float delta_second)
{
}

void JumpingState::Draw() const
{
}

void JumpingState::Finalize()
{
}

ePlayerState JumpingState::GetState() const
{
	return ePlayerState::JUMP;
}
