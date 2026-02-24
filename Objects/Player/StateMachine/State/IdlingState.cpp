#include "IdlingState.h"

#include "DxLib.h"
#include "../../../../Utility/InputControl.h"
#include "../../Player.h"

int Idling_animation[2] = { 0,1 };
int count = 0;
int anime = 0;

IdlingState::IdlingState(class Player* p) :
	PlayerStateBase(p),
	input(nullptr)
{
	/*LoadDivGraph("Resource/image/Player/Normal/Normal_Idle.png", 2, 2, 1, 200, 200, Idling_animation);*/
}

IdlingState::~IdlingState()
{
}

void IdlingState::Initialize()
{
	input = InputControl::GetInstance();

	ResourceManager* rm = ResourceManager::GetInstance();

	player_normal_img = rm->GetImages("Resource/image/Player/Normal/Idling/Normal_Idling_1.png", 1, 1, 1, 16, 16);
}

void IdlingState::Update(float delta_second)
{
	count++;
	if (count % 10 == 0)
	{
		count = 0;
		anime++;
		if (anime >= 2)
		{
			anime = (anime + 1) % 2;
		}
	}
	if(this->player->velocity.x < 0)
	{
		this->player->velocity.x += D_PLAYER_SPEED * delta_second;
	}
	if (this->player->velocity.x > 0)
	{
		this->player->velocity.x -= D_PLAYER_SPEED * delta_second;
	}
	if (this->player->velocity.x < 1.0f && this->player->velocity.x > -1.0f)
	{
		this->player->velocity.x = 0.0f;
	}

	if(input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_LEFT) == ePadInputState::eHold ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_DPAD_RIGHT) == ePadInputState::eHold)
	{
		player->SetNextState(ePlayerState::ROLL);
	}

	if(input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::ePress ||
		input->GetButtonInputState(XINPUT_BUTTON_B) == ePadInputState::eHold)
	{
		player->SetNextState(ePlayerState::JUMP);
	}
}

void IdlingState::Draw() const
{
	//À•Wî•ñ‚ð®”’l‚É•ÏŠ·
	int x = 0, y = 0;
	player->GetLocation().ToInt(&x, &y);
	DrawRotaGraph(x, y, 1.0, 0.0, Idling_animation[anime], TRUE);
}

void IdlingState::Finalize()
{
}

void IdlingState::Animation(float delta_second)
{
	player->image = player_normal_img[0];
}

ePlayerState IdlingState::GetState() const
{
	return ePlayerState::IDLE;
}
