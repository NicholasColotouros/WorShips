// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "WorshipBoat.h"
#include "VehicleAIController.h"

void AWorshipBoat::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AVehicleAIController* AIController = Cast<AVehicleAIController>(GetController());
}
