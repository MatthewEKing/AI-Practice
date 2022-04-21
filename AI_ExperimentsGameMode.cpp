// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_ExperimentsGameMode.h"
#include "AI_ExperimentsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_ExperimentsGameMode::AAI_ExperimentsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
