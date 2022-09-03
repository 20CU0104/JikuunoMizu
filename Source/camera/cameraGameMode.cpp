// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "cameraGameMode.h"
#include "cameraCharacter.h"
#include "UObject/ConstructorHelpers.h"

AcameraGameMode::AcameraGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
