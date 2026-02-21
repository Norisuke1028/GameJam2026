#include "IdlingState.h"

#include "DxLib.h"
#include "../../../../Utility/InputControl.h"
#include "../../Player.h"

IdlingState::IdlingState(class Player* p) :
	PlayerStateBase(p),
	input(nullptr)
{
}

IdlingState::~IdlingState()
{
}

void IdlingState::Initialize()
{
	input = InputControl::GetInstance();
}

void IdlingState::Update(float delta_second)
{
	if(this->player->velocity.x < 0)
	{
		this->player->velocity.x += D_PLAYER_SPEED * delta_second;
	}
	if (this->player->velocity.x > 0)
	{
		this->player->velocity.x -= D_PLAYER_SPEED * delta_second;
	}
	if (this->player->velocity.x < 2.0f && this->player->velocity.x > -2.0f)
	{
		this->player->velocity.x = 0.0f;
	}

	if(input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::eHeld ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::eHeld)
	{
		player->SetNextState(ePlayerState::ROLL);
	}

	if(input->GetButtonInputState(XINPUT_BUTTON_A) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_A) == ePadInputState::eHeld)
	{
		player->SetNextState(ePlayerState::JUMP);
	}
}

void IdlingState::Draw() const
{
	//À•Wî•ñ‚ð®”’l‚É•ÏŠ·
	int x = 0, y = 0;
	player->GetLocation().ToInt(&x, &y);
}

void IdlingState::Finalize()
{
}

ePlayerState IdlingState::GetState() const
{
	return ePlayerState::IDLE;
}
