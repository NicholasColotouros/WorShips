// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Worship.h"
#include "WorshipCharacter.h"

//////////////////////////////////////////////////////////////////////////
// AWorshipCharacter

AWorshipCharacter::AWorshipCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	CheatCodeInput = new RotatingArray<EControllerInputEnum::Type>(MaxCheatCodeLength);
	InitializeCheatCodes();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AWorshipCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


	InputComponent->BindAction("TargetSpell", IE_Pressed, this, &AWorshipCharacter::TargetSpellViewPressed);
	InputComponent->BindAction("TargetSpell", IE_Released, this, &AWorshipCharacter::TargetSpellViewReleased);

	InputComponent->BindAxis("MoveForward", this, &AWorshipCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AWorshipCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AWorshipCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AWorshipCharacter::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &AWorshipCharacter::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AWorshipCharacter::TouchStopped);
}


void AWorshipCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void AWorshipCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void AWorshipCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AWorshipCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AWorshipCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AWorshipCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AWorshipCharacter::TargetSpellViewPressed()
{
	CameraBoom->TargetArmLength = 2000.0f;
}


void AWorshipCharacter::TargetSpellViewReleased()
{
	CameraBoom->TargetArmLength = 300.0f;
}

void AWorshipCharacter::CheatCodeButtonPressed()
{
	APlayerController* controller = Cast<APlayerController, AController>(Controller);
	if (controller)
	{
		// DPad
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_DPad_Down)) { CheatCodeInput->Add(EControllerInputEnum::DOWN); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_DPad_Left)) { CheatCodeInput->Add(EControllerInputEnum::LEFT); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_DPad_Right)) { CheatCodeInput->Add(EControllerInputEnum::RIGHT); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_DPad_Up)) { CheatCodeInput->Add(EControllerInputEnum::UP); }

		// Start/Select
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_Special_Left)) { CheatCodeInput->Add(EControllerInputEnum::SELECT); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_Special_Right)) { CheatCodeInput->Add(EControllerInputEnum::START); }

		// Face Buttons
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Bottom)) { CheatCodeInput->Add(EControllerInputEnum::A); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Left)) { CheatCodeInput->Add(EControllerInputEnum::X); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Right)) { CheatCodeInput->Add(EControllerInputEnum::B); }
		if (controller->WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Top)) { CheatCodeInput->Add(EControllerInputEnum::Y); }
	}
}

void AWorshipCharacter::InitializeCheatCodes()
{
	CheatCodes = new TMap<ECheatCodeEnum::Type, TArray<EControllerInputEnum::Type>>();

	// Insert the konami Code
	TArray<EControllerInputEnum::Type>* konamiCode = new TArray<EControllerInputEnum::Type>();
	konamiCode->Add(EControllerInputEnum::UP);
	konamiCode->Add(EControllerInputEnum::UP);
	konamiCode->Add(EControllerInputEnum::DOWN);
	konamiCode->Add(EControllerInputEnum::DOWN);
	konamiCode->Add(EControllerInputEnum::LEFT);
	konamiCode->Add(EControllerInputEnum::RIGHT);
	konamiCode->Add(EControllerInputEnum::LEFT);
	konamiCode->Add(EControllerInputEnum::RIGHT);
	konamiCode->Add(EControllerInputEnum::B);
	konamiCode->Add(EControllerInputEnum::A);
	konamiCode->Add(EControllerInputEnum::START);

	CheatCodes->Add(ECheatCodeEnum::KONAMICODE, *konamiCode);
}

// Checks input and returns the matching cheat code, if any
ECheatCodeEnum::Type AWorshipCharacter::CheckCheatCodeInput()
{
	if (CheatCodes && CheatCodeInput)
	{
		for (auto cheatCodeIt = CheatCodes->CreateIterator(); cheatCodeIt; ++cheatCodeIt)
		{
			ECheatCodeEnum::Type code = cheatCodeIt.Key();
			TArray<EControllerInputEnum::Type>& codeSequence = cheatCodeIt.Value();

			bool sequenceMatched = true;
			for (int i = 0; i < codeSequence.Num(); i++)
			{
				if (codeSequence[i] != CheatCodeInput->Get(i))
				{
					sequenceMatched = false;
				}
			}
			if (sequenceMatched)
			{
				return code;
			}
		}
	}
	return ECheatCodeEnum::NONE;
}