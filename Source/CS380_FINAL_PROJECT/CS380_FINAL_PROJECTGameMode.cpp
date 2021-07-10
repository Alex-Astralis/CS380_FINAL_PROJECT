// Copyright Epic Games, Inc. All Rights Reserved.

#include "CS380_FINAL_PROJECTGameMode.h"
#include "CS380_FINAL_PROJECTCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACS380_FINAL_PROJECTGameMode::ACS380_FINAL_PROJECTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
