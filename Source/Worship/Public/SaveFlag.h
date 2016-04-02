// Fill out your copyright notice in the Description page of Project Settings.
/*
* Author: Terrence KO
*/
#pragma once

#include "GameFramework/Actor.h"
#include "SaveFlag.generated.h"

UCLASS()
class WORSHIP_API ASaveFlag : public AActor
{
	GENERATED_BODY()
	
public:	
	ASaveFlag(const FObjectInitializer& ObjectInitializer);

	//    sphere component for colliding
	USphereComponent* CollisionComp;
	UFUNCTION()
	void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Our server function to update the score.
	UFUNCTION(Reliable, Server, WithValidation)
	void SaveGame();
	
	void SaveGame_Implementation();
	
	bool SaveGame_Validate();
	
	
};
