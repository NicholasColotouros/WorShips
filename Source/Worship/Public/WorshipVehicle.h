/**
	A base class for vehicles used in the game designed to expose information from Blueprints using stub methods
	so that the AI can be written in C++ rather than blueprints.

	@author Nicholas Nathan Colotouros
*/


#pragma once

#include "GameFramework/Pawn.h"
#include "WorshipVehicle.generated.h"

UCLASS()
class WORSHIP_API AWorshipVehicle : public APawn
{
	GENERATED_BODY()

public:

	// Sets default values for this pawn's properties
	AWorshipVehicle();

	//virtual void Turn(float axisValue);
	//virtual void LookUp(float axisValue);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:
	UPROPERTY(Replicated, EditDefaultsOnly, BlueprintReadWrite, Category = DmgSystem)
		float Health;
	
	UPROPERTY(Replicated, EditDefaultsOnly, BlueprintReadWrite, Category = DmgSystem)
		bool WasKilledByGodPower;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = DmgSystem)
		APawn* CurrentlyPossessing;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = DmgSystem)
		void Die();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
		void Turn(float axisValue);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Controls)
		void LookUp(float axisValue);
};
