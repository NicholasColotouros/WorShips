// Fill out your copyright notice in the Description page of Project Settings.

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
	if (DistanceBetween < 5000.0f)
	{
		CurrentPawn->Fire();
	}
	return EBTNodeResult::Succeeded;


	//FRotator PlayerAimRotation = PlayerPawn->GetBaseAimRotation();
	//PlayerAimRotation.Roll = 0.0f;
	//PlayerAimRotation.Pitch = 0.0f;
	//FQuat PawnRotInput = PlayerAimRotation.Quaternion();
	//CurrentPawn->SetActorRotation(PawnRotInput);

	//check if shooting the boat it's on
	//AWorshipBoat* BoatParent = Cast<AWorshipBoat>(CurrentPawn->GetAttachParentActor());


	//got through the list of active players and check if they're in line of sight
	//FConstPlayerControllerIterator itPlayers = OwnerComp.GetWorld()->GetPlayerControllerIterator();
	//while (itPlayers)
	//{
	//	APlayerController* player = *itPlayers;
	//	FVector controllerViewPoint;
	//	FRotator controllerRotator;
	//	CurrentController->GetActorEyesViewPoint(controllerViewPoint,controllerRotator);
	//	//check if the player is in the controller's line of sight
	//	bool canShoot = CurrentController->LineOfSightTo(player,controllerViewPoint,false);
	//	if (canShoot)
	//	{
	//		FRotator playerRotator = player->GetControlRotation();
	//		playerRotator.Yaw += 90.0f;
	//		FQuat playerQuat = playerRotator.Quaternion();
	//		//FVector eulerConvert = playerQuat.Euler();
	//		//eulerConvert.Z += 90.0f;
	//		//playerQuat = eulerConvert.Rotation().Quaternion();
	//		CurrentPawn->SetActorRotation(playerQuat);
	//		break;
	//	}
	//	//move to the next player
	//	itPlayers++;
	//}

	//
	//CurrentPawn->Fire();
	//return EBTNodeResult::Succeeded;
}