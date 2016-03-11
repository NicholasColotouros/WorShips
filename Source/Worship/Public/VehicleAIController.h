// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "VehicleAIController.generated.h"

/**
 * 
 */
UCLASS()
class WORSHIP_API AVehicleAIController : public AAIController
{
	GENERATED_BODY()

	AVehicleAIController(const class FObjectInitializer& ObjectInitializer);

	void AVehicleAIController::Possess(class APawn* InGamePawn);

	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;
	
	
	
};
