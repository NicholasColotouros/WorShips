// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorshipCharacter.h"
#include "GameFramework/Character.h"
#include "SCrewMenCharacter.generated.h"



UCLASS()
class WORSHIP_API ASCrewMenCharacter : public ACharacter
{
	GENERATED_BODY()

	float LastTimeSeen;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UPawnSensingComponent* PawnSensingComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void SetupPlayerInputComponent(UInputComponent * InputComponent);

protected:
	//Triggered when a crewmen sees a player
	UFUNCTION()
		void OnSeePlayer(APawn* Pawn);

public:
	// Sets default values for this character's properties
	ASCrewMenCharacter(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;

};
