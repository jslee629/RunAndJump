#include "RunAndJumpGameModeBase.h"
#include "Global.h"
#include "Player/JPlayer.h"

ARunAndJumpGameModeBase::ARunAndJumpGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "/Game/Character/BP_JPlayer");
}