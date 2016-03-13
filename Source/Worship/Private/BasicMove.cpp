// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "BasicMove.h"
#include "WorshipBoatAIController.h"
#include "WorshipBoat.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
/* This contains includes all key types like UBlackboardKeyType_Vector used below. */
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

EBTNodeResult::Type UBasicMove::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AWorshipBoatAIController* CurrentController = Cast<AWorshipBoatAIController>(OwnerComp.GetAIOwner());
	if (CurrentController == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AWorshipBoat* CurrentPawn = Cast<AWorshipBoat>(CurrentController->GetControlledPawn());
	if (CurrentPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	for (size_t i = 0; i < 5; i++)
	{
		CurrentPawn->GearUp();
	}
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if (PlayerPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	FVector Waypoint = PlayerPawn->GetActorLocation();
	OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), Waypoint);

	return EBTNodeResult::Succeeded;
	
}
