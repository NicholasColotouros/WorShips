// Fill out your copyright notice in the Description page of Project Settings.
/*
* Author: Terrence KO
*/
#include "Worship.h"
#include "SaveFlag.h"

#include "Engine.h"
// Include our game mode for casting.
#include "WorshipGameMode.h"

ASaveFlag::ASaveFlag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	//ObjectInitializer
	bReplicates = true;
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(80.0f);
	RootComponent = CollisionComp;
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ASaveFlag::OnOverlapBegin);
}

void ASaveFlag::OnOverlapBegin(AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Role == ROLE_Authority) {
		SaveGame();
	}
}


void ASaveFlag::SaveGame_Implementation()
{
	// Get the game mode and cast it to our game mode.
	AWorshipGameMode* TheGameMode = Cast<AWorshipGameMode>(GetWorld()->GetAuthGameMode());
	//Add Score!
	const FVector playerLocation = GetActorLocation();
	TheGameMode->SaveGame(playerLocation, 1);
}

bool ASaveFlag::SaveGame_Validate()
{
	return true;
}
