// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "DmgSystem")
	int32 Health;
	
	virtual void TakeDamage(int32 damageDealt);
	virtual void Die();

	virtual void Turn(float axisValue);
	virtual void LookUp(float axisValue);


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;



};
