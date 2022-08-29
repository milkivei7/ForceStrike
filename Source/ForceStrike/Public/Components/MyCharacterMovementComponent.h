// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FORCESTRIKE_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
	public:
		virtual float GetMaxSpeed() const override;

	protected:    
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "1.1", ClampMax = "5.0"))
		float RunModifier = 2.0f;
};
