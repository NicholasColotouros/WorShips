// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "Worship/Public/RotatingArray.h"
#include "GameFramework/Character.h"
#include "WorshipCharacter.generated.h"

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

UCLASS(config = Game)
class AWorshipCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AWorshipCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when target spell view is active **/
	void TargetSpellViewPressed();

	/** Handler for when target spell view is released **/
	void TargetSpellViewReleased();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:

	// Handles cheat code input
	const int MaxCheatCodeLength = 11;
	RotatingArray<EControllerInputEnum::Type> *CheatCodeInput;
	TMap<ECheatCodeEnum::Type, TArray<EControllerInputEnum::Type>> *CheatCodes;

	void InitializeCheatCodes();
	void CheatCodeButtonPressed();
	ECheatCodeEnum::Type CheckCheatCodeInput();
	void ActivateCheatCode();
};

