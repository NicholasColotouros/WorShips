// Fill out your copyright notice in the Description page of Project Settings.

/*
* Author: Philippe Tremblay, Chuong Trinh
*/
#include "Worship.h"
#include "FireBolt.h"
#include "WorshipBallista.h"
#include "BallistaAIController.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UFireBolt::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	ABallistaAIController* CurrentController = Cast<ABallistaAIController>(OwnerComp.GetAIOwner());
	AWorshipBallista* CurrentPawn = Cast<AWorshipBallista>(CurrentController->GetControlledPawn());
	if (CurrentPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	float DistanceBetween = CurrentPawn->GetDistanceTo(PlayerPawn);
	if (DistanceBetween < 10000.0f)
	{
		CurrentPawn->Fire();
	}
	return EBTNodeResult::Succeeded;
}