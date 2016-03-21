// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "FireBolt.h"
#include "WorshipBallista.h"
#include "BallistaAIController.h"

EBTNodeResult::Type UFireBolt::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	ABallistaAIController* CurrentController = Cast<ABallistaAIController>(OwnerComp.GetAIOwner());
	AWorshipBallista* CurrentPawn = Cast<AWorshipBallista>(CurrentController->GetControlledPawn());
	if (CurrentPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	CurrentPawn->Fire();
	return EBTNodeResult::Succeeded;
}
 //work in progress lol