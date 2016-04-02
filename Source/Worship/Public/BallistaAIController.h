// Fill out your copyright notice in the Description page of Project Settings.
/*
* Author: Philippe Tremblay, Chuong Trinh
*/

#pragma once

#include "AIController.h"
#include "BallistaAIController.generated.h"

/**
 * 
 */
UCLASS()
class WORSHIP_API ABallistaAIController : public AAIController
{
	GENERATED_BODY()
	
		ABallistaAIController(const class FObjectInitializer& ObjectInitializer);

	void ABallistaAIController::Possess(class APawn* InGamePawn) override;

	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;
	

};
