// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MyCharacterMovementComponent.h"
#include "Player/FirstCharacter.h"

float UMyCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const AFirstCharacter *Player = Cast<AFirstCharacter>(GetPawnOwner());

    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;

}
