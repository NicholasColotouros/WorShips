// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "TargetPlayerBoat.h"
#include "WorshipBoatAIController.h"
#include "WorshipBoat.h"
#include "Kismet/KismetMathLibrary.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UTargetPlayerBoat::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
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
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	//get the player's location
	FVector PlayerLocation3D = PlayerPawn->GetActorLocation();
	//get the ai pawn's location
	FVector CurrentPawnLocation3D = CurrentPawn->GetActorLocation();

	//convert to 2D
	FVector2D PlayerLocation = FVector2D(PlayerLocation3D);
	FVector2D CurrentPawnLocation = FVector2D(CurrentPawnLocation3D);

	float Theta = UKismetMathLibrary::Atan2((PlayerLocation.Component(1) - CurrentPawnLocation.Component(1)),
		(PlayerLocation.Component(0) - CurrentPawnLocation.Component(0)));
	//converting to degrees
	float ThetaDeg = FMath::RadiansToDegrees(Theta);
	//add 90 to clamp it to the y axis
	ThetaDeg = ThetaDeg + 90.0f;

	float BoatYaw = 0.0f;
	float BoatPitch = 0.0f;
	float BoatRoll = 0.0f;

	UKismetMathLibrary::BreakRotator(CurrentPawn->GetActorRotation(),BoatRoll,BoatPitch,BoatYaw);
	
	//do this
	if (ThetaDeg < BoatYaw - 180) {
		ThetaDeg = ThetaDeg + 360;
	}
	else if (ThetaDeg > BoatYaw + 180) {
		ThetaDeg = ThetaDeg - 360;
	}

	float ThetaCurrentFacingAngle = ThetaDeg - BoatYaw;

	if (ThetaCurrentFacingAngle > 0.0f)
	{
		//turn right
		CurrentPawn->Turn(10.0);
	}
	else 
	{
		//turn left
		CurrentPawn->Turn(-10.0);
	}
	
	return EBTNodeResult::Succeeded;
}
