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
	for (size_t i = 0; i < 2; i++)
	{
		CurrentPawn->Turn(90.0);
	}
	
	/*APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if (PlayerPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	//get the player's location
	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	//get the ai pawn's location
	FVector CurrentPawnLocation = CurrentPawn->GetActorLocation();
	//substract to get get "directional" vector from the ai boat to the player's boat
	FVector DirectionalVector = PlayerLocation - CurrentPawnLocation;

	//Calculate the distance between 2 vectors
	float DVectorLength = PlayerLocation.Size();
	float CLocationLenght = CurrentPawnLocation.Size();
	float CLocationDotDVector = FVector::DotProduct(CurrentPawnLocation, DirectionalVector);

	float angle = UKismetMathLibrary::Acos(CLocationDotDVector / (CLocationLenght*DVectorLength));

	if (angle >= 0 && angle <= 180)
	{
		//turn right
		CurrentPawn->Turn(45.0);
	}
	else if (angle > 180 && angle < 360)
	{
		//turn left
		CurrentPawn->Turn(-90.0);
	}*/

	return EBTNodeResult::Succeeded;
	
}
