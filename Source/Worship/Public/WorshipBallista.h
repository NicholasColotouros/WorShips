/**
	A base class for the ballista in the game designed to expose information from Blueprints
	using stub methods so that the AI can be written in C++ rather than blueprints.

	@author Nicholas Nathan Colotouros
*/


#pragma once

#include "WorshipVehicle.h"
#include "WorshipBallista.generated.h"

/**
 *
 */
UCLASS()
class WORSHIP_API AWorshipBallista : public AWorshipVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;


};
