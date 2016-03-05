// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SCrewMenTargetPoint.h"
#include "AIController.h"
#include "SCrewMenCharacter.h"
#include "SCrewMenController.generated.h"



/**
*
*/
UCLASS()
class WORSHIP_API ASCrewMenController : public AAIController
{
	GENERATED_BODY()

	ASCrewMenController(const class FObjectInitializer& ObjectInitializer);

	virtual void Possess(class APawn* InPawn) override;

	virtual void UnPossess() override;

	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName CurrentWaypointKeyName;

public:
	ASCrewMenTargetPoint* GetWayPoint();

	AWorshipCharacter* GetTargetEnemy();

	void SetTargetEnemy(APawn* NewTarget);

	void SetWayPoint(ASCrewMenTargetPoint* NewTargetPoint);

	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

};
