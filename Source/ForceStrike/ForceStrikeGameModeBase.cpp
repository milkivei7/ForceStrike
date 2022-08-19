// Copyright Epic Games, Inc. All Rights Reserved.


#include "ForceStrikeGameModeBase.h"
#include "Player/FirstCharacter.h"
#include "Player/FirstPlayerController.h"

AForceStrikeGameModeBase::AForceStrikeGameModeBase()
{
    DefaultPawnClass = AFirstCharacter::StaticClass();
    PlayerControllerClass = AFirstPlayerController::StaticClass();
}