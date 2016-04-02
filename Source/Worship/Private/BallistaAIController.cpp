// Fill out your copyright notice in the Description page of Project Settings.
/*
* Author: Philippe Tremblay, Chuong Trinh
*/
#include "Worship.h"
#include "BallistaAIController.h"
#include "WorshipBallista.h"

/* AI Specific includes */
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ABallistaAIController::ABallistaAIController(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
}

void ABallistaAIController::Possess(APawn * InGamePawn)
{
	Super::Possess(InGamePawn);

	AWorshipBallista* BallistaBot = Cast<AWorshipBallista>(InGamePawn);
	if (BallistaBot)
	{
		if (BallistaBot->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*BallistaBot->BehaviorTree->BlackboardAsset);
		}
		BehaviorComp->StartTree(*BallistaBot->BehaviorTree);
	}
}
