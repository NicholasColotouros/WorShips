// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorshipVehicle.h"
#include "WorshipBoat.generated.h"

/**
 *
 */
UCLASS()
class WORSHIP_API AWorshipBoat : public AWorshipVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
		void GearUp();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
		void GearDown();

};
