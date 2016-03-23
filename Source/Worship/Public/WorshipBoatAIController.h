// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "WorshipBoatAIController.generated.h"

/**
 * 
 */
UCLASS()
class WORSHIP_API AWorshipBoatAIController : public AAIController
{
	GENERATED_BODY()
	
	AWorshipBoatAIController(const class FObjectInitializer& ObjectInitializer);

	void AWorshipBoatAIController::Possess(class APawn* InGamePawn) override;

	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;	

};
