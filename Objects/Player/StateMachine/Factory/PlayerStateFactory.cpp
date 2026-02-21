#include "PlayerStateFactory.h"

#include "../State/IdlingState.h"
#include "../State/JumpingState.h"
#include "../State/RollingState.h"
#include "../State/ClearState.h"
#include "../State/DyingState.h"

#include "../../Player.h"

void PlayerStateFactory::Initialize(class Player& player)
{
	idle = new IdlingState(&player);
	roll = new RollingState(&player);
	jump = new JumpingState(&player);
	clear = new ClearState(&player);
	die = new DyingState(&player);
}

PlayerStateBase* PlayerStateFactory::Get(Player& player, ePlayerState type)
{
	return nullptr;
}
