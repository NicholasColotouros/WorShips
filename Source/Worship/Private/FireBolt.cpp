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

	//got through the list of active players and check if they're in line of sight
	FConstPlayerControllerIterator itPlayers = OwnerComp.GetWorld()->GetPlayerControllerIterator();
	while (itPlayers)
	{
		APlayerController* player = *itPlayers;
		FVector controllerViewPoint;
		FRotator controllerRotator;
		CurrentController->GetActorEyesViewPoint(controllerViewPoint,controllerRotator);
		//check if the player is in the controller's line of sight
		bool canShoot = CurrentController->LineOfSightTo(player,controllerViewPoint,false);
		if (canShoot)
		{
			CurrentController->SetFocus(player, EAIFocusPriority::Move);
			FAIMoveRequest targetPlayer = FAIMoveRequest(player);
			CurrentController->MoveTo(targetPlayer);
			break;
		}
		//move to the next player
		itPlayers++;
	}

	
	CurrentPawn->Fire();
	return EBTNodeResult::Succeeded;
}
 //work in progress lol