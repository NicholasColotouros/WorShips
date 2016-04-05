// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*
* Author: Terrence KO
*/
#pragma once
#include "GameFramework/GameMode.h"
#include "WorshipGameMode.generated.h"

UCLASS(minimalapi)
class AWorshipGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AWorshipGameMode(const FObjectInitializer& ObjectInitializer);
	//Function to add score.
	void AddMana(int32 Amount);
	// void ANetworkGameMode::AddHealth(int32 Amount, int32 Player);
	void SaveGame(FVector PlayerLocaton, int32 NumEnemy);
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Utility)
    APawn* PlayerBoat;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Utility)
    void GetPlayerBoat();

	//getting the last location from most recent checkpoint file
	FVector LoadGame();
};



