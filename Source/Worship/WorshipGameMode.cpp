// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

/*
* Author: Terrence KO
*/
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

void AWorshipGameMode::SaveGame(FVector PlayerLocation, int32 NumEnemy)
{
	JsonHelper j;
	j.setJsonObject("test.json",PlayerLocation,NumEnemy);
}

FVector AWorshipGameMode::LoadGame()
{
	JsonHelper j;
	TSharedPtr<FJsonObject> JsonObject = j.loadJsonObject("test.json");
	FVector PlayerLocation;
	PlayerLocation.X = JsonObject->GetNumberField("spawnX");
	PlayerLocation.Y = JsonObject->GetNumberField("spawnY");
	PlayerLocation.Z = JsonObject->GetNumberField("spawnZ");

	int32 NumEnemies = JsonObject->GetIntegerField("enemies");

	return PlayerLocation;
	

}
