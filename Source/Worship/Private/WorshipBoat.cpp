/**
	@author Nicholas Nathan Colotouros
*/

#include "Worship.h"
#include "WorshipBoat.h"
#include "WorshipBoatAIController.h"

void AWorshipBoat::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AWorshipBoatAIController* AIController = Cast<AWorshipBoatAIController>(GetController());
}
