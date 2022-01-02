// Copyright Epic Games, Inc. All Rights Reserved.

#include "AtrophiaTestGameMode.h"
#include "AtrophiaTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAtrophiaTestGameMode::AAtrophiaTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
