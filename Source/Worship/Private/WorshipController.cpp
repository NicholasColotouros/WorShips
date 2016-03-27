/**
	@author Nicholas Nathan Colotouros
*/
#include "Worship.h"
#include "WorshipController.h"

AWorshipController::AWorshipController()
{
	CheatCodeInput = new RotatingArray<EControllerInputEnum::Type>(MaxCheatCodeLength);
	InitializeCheatCodes();
}

void AWorshipController::CheatCodeButtonPressed()
{
	// DPad
	if (WasInputKeyJustPressed(EKeys::Gamepad_DPad_Down)) { CheatCodeInput->Add(EControllerInputEnum::DOWN); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_DPad_Left)) { CheatCodeInput->Add(EControllerInputEnum::LEFT); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_DPad_Right)) { CheatCodeInput->Add(EControllerInputEnum::RIGHT); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_DPad_Up)) { CheatCodeInput->Add(EControllerInputEnum::UP); }

	// Start/Select
	if (WasInputKeyJustPressed(EKeys::Gamepad_Special_Left)) { CheatCodeInput->Add(EControllerInputEnum::SELECT); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_Special_Right)) { CheatCodeInput->Add(EControllerInputEnum::START); }

	// Face Buttons
	if (WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Bottom)) { CheatCodeInput->Add(EControllerInputEnum::A); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Left)) { CheatCodeInput->Add(EControllerInputEnum::X); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Right)) { CheatCodeInput->Add(EControllerInputEnum::B); }
	if (WasInputKeyJustPressed(EKeys::Gamepad_FaceButton_Top)) { CheatCodeInput->Add(EControllerInputEnum::Y); }
}

void AWorshipController::InitializeCheatCodes()
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

	CheatCodes->Add(ECheatCodeEnum::KONAMICODE, *konamiCode);
}

// Checks input and returns the matching cheat code, if any
ECheatCodeEnum::Type AWorshipController::CheckCheatCodeInput()
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