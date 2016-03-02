// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "SCrewMenCharacter.h"
#include "SCrewMenController.h"

#include "Perception/PawnSensingComponent.h"

// Sets default values
ASCrewMenCharacter::ASCrewMenCharacter(const class FObjectInitializer& ObjectInitializer)
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASCrewMenCharacter::OnSeePlayer(APawn * Pawn)
{
	ASCrewMenController* CrewAi = Cast<ASCrewMenController>(GetController());
	AWorshipCharacter* SensedPlayer = Cast<AWorshipCharacter>(Pawn);

	CrewAi->SetTargetEnemy(SensedPlayer);
}

// Called when the game starts or when spawned
void ASCrewMenCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ASCrewMenCharacter::OnSeePlayer);
	}

}

// Called every frame
void ASCrewMenCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCrewMenCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

