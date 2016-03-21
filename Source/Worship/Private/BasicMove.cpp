// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "BasicMove.h"
#include "WorshipBoatAIController.h"
#include "WorshipBoat.h"
#include "Kismet/KismetMathLibrary.h"

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
	for (size_t i = 0; i < 4; i++)
	{
		CurrentPawn->GearUp();
		
	}

	//set the blackboard value of isMoving to prevent this from being called
	OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(BlackboardKey.GetSelectedKeyID(), true);

	return EBTNodeResult::Succeeded;
	
}
