// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "WorshipBoat.h"
#include "VehicleAIController.h"

/* AI Specific includes */
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AVehicleAIController::AVehicleAIController(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
}

void AVehicleAIController::Possess(APawn* InGamePawn)
{
	Super::Possess(InGamePawn);

	AWorshipBoat* BoatBot = Cast<AWorshipBoat>(InGamePawn);
	if (BoatBot)
	{
		if (BoatBot->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*BoatBot->BehaviorTree->BlackboardAsset);
		}
		BehaviorComp->StartTree(*BoatBot->BehaviorTree);
	}
}
