// Fill out your copyright notice in the Description page of Project Settings.

#include "Worship.h"
#include "WorshipVehicle.h"

// Sets default values
AWorshipVehicle::AWorshipVehicle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorshipVehicle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWorshipVehicle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AWorshipVehicle::TakeDamage(int32 damageDealt)
{
	Health -= damageDealt;
	if (Health <= 0) Die();
}

void AWorshipVehicle::Die()
{
	Destroy();
}

// Called to bind functionality to input
void AWorshipVehicle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

