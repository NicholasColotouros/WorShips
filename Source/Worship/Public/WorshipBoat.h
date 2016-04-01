/**
	A base class for the boats (man of war, player boat) used in the game designed to expose information from Blueprints 
	using stub methods so that the AI can be written in C++ rather than blueprints.

	@author Nicholas Nathan Colotouros
*/


#pragma once

#include "WorshipVehicle.h"
#include "WorshipBoat.generated.h"

UCLASS()
class WORSHIP_API AWorshipBoat : public AWorshipVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
	void GearUp();

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
	void GearDown();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;
};
