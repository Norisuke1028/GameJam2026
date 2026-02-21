#include "IdlingState.h"

#include "DxLib.h"
#include "../PlayerStateBase.h"

IdlingState::IdlingState(class Player* p) :
	PlayerStateBase(p)
{
}

IdlingState::~IdlingState()
{
}

void IdlingState::Initialize()
{
}

void IdlingState::Update(float delta_second)
{
}

void IdlingState::Draw() const
{
}

void IdlingState::Finalize()
{
}

ePlayerState IdlingState::GetState() const
{
	return ePlayerState::IDLE;
}
