// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "SCrewMenController.h"
#include "SCrewMenCharacter.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ASCrewMenController::ASCrewMenController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	CurrentWaypointKeyName = "CurrentWaypoint";
	TargetEnemyKeyName = "TargetEnemy";
}

void ASCrewMenController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	ASCrewMenCharacter* crewMan = Cast<ASCrewMenCharacter>(InPawn);
	if (crewMan)
	{
		if (crewMan->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*crewMan->BehaviorTree->BlackboardAsset);
		}
		BehaviorComp->StartTree(*crewMan->BehaviorTree);
	}
}


void ASCrewMenController::UnPossess()
{
	Super::UnPossess();

	BehaviorComp->StopTree();
}

void ASCrewMenController::SetTargetEnemy(APawn * NewTarget)
{
	if (BehaviorComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}

void ASCrewMenController::SetWayPoint(ASCrewMenTargetPoint * NewTargetPoint)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTargetPoint);
	}
}

ASCrewMenTargetPoint* ASCrewMenController::GetWayPoint()
{
	if (BlackboardComp)
	{
		return Cast<ASCrewMenTargetPoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
	}
	return nullptr;
}

AWorshipCharacter* ASCrewMenController::GetTargetEnemy()
{
	if (BlackboardComp)
	{
		return Cast<AWorshipCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}
	return nullptr;
}
