/**
	The base C++ class which houses the cheat code input. This class is extended in blueprints.

	@author Nicholas Nathan Colotouros
*/

#pragma once

#include "GameFramework/PlayerController.h"
#include "Worship/Public/RotatingArray.h"
#include "WorshipController.generated.h"

UENUM(BlueprintType)
namespace EControllerInputEnum
{
	enum Type
	{
		A		UMETA(DisplayName = "A Button"),
		B		UMETA(DisplayName = "B Button"),
		X		UMETA(DisplayName = "X Button"),
		Y		UMETA(DisplayName = "Y Button"),

		UP		UMETA(DisplayName = "D-Pad Up"),
		DOWN	UMETA(DisplayName = "D-Pad Down"),
		LEFT	UMETA(DisplayName = "D-Pad Left"),
		RIGHT	UMETA(DisplayName = "D-Pad Right"),

		START	UMETA(DisplayName = "Start Button"),
		SELECT	UMETA(DisplayName = "Select Button")
	};
}

UENUM(BlueprintType)
namespace ECheatCodeEnum
{
	enum Type
	{
		NONE		UMETA(DisplayName = "None"),
		KONAMICODE	UMETA(DisplayName = "Konami Code")
	};
}

UCLASS()
class WORSHIP_API AWorshipController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AWorshipController();

	// Records the last cheat code button pressed
	UFUNCTION(BlueprintCallable, Category = Cheats)
	ECheatCodeEnum::Type CheckCheatCodeInput();

	// Returns the cheat code entered if any
	UFUNCTION(BlueprintCallable, Category = Cheats)
	void CheatCodeButtonPressed();

	
private:

	// Handles cheat code input
	const int MaxCheatCodeLength = 11;
	RotatingArray<EControllerInputEnum::Type> *CheatCodeInput;
	TMap<ECheatCodeEnum::Type, TArray<EControllerInputEnum::Type>> *CheatCodes;

	void InitializeCheatCodes();
};
