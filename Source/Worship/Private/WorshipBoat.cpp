// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "WorshipBoat.h"
#include "WorshipBoatAIController.h"

void AWorshipBoat::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AWorshipBoatAIController* AIController = Cast<AWorshipBoatAIController>(GetController());
}
