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


	virtual void Tick(float DeltaSeconds) override;

<<<<<<< HEAD
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
		void GearDown();
=======
	virtual void BeginPlay() override;
>>>>>>> 8c09603bcf2ebb65e0ae50db6c4bab82f0ffefbf

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;
};
