/**
	@author Nicholas Nathan Colotouros
*/
#include "Worship.h"
#include "WorshipVehicle.h"

#include "Engine.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AWorshipVehicle::AWorshipVehicle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void AWorshipVehicle::GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWorshipVehicle, Health);
	DOREPLIFETIME(AWorshipVehicle, WasKilledByGodPower);
}

// Called when the game starts or when spawned
void AWorshipVehicle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWorshipVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWorshipVehicle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}