// Copyright Epic Games, Inc. All Rights Reserved.

#include "InvSysGameMode.h"
#include "InvSysCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInvSysGameMode::AInvSysGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
