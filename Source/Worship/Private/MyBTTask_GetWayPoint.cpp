// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "MyBTTask_GetWayPoint.h"
#include "SCrewMenTargetPoint.h"
#include "SCrewMenController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

EBTNodeResult::Type UMyBTTask_GetWayPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	ASCrewMenController* MyController = Cast<ASCrewMenController>(OwnerComp.GetAIOwner());
	if (MyController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	ASCrewMenTargetPoint* CurrentWaypoint = MyController->GetWayPoint();
	AActor* NewWaypoint = nullptr;

	TArray<AActor*> AllWaypoints;
	UGameplayStatics::GetAllActorsOfClass(MyController, ASCrewMenTargetPoint::StaticClass(), AllWaypoints);

	if (AllWaypoints.Num() == 0)
	{
		return EBTNodeResult::Failed;
	}

	NewWaypoint = AllWaypoints[FMath::RandRange(0, AllWaypoints.Num() - 1)];

	if (NewWaypoint)
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), NewWaypoint);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
