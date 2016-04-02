// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Worship.h"
#include "WorshipGameMode.h"
#include "WorshipCharacter.h"
#include "JsonHelper.h"

AWorshipGameMode::AWorshipGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	// set default pawn class to our Blueprinted character
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ShipsAndExamples/CustomThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AWorshipGameMode::AddMana(int32 Amount)
{
	//to be implemented
}

void AWorshipGameMode::SaveGame()
{
	JsonHelper j;
	j.setJsonObject("test.json");
}
