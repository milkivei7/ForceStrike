// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"

#include "Components/InputComponent.h"


#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

#include "FirstCharacter.generated.h"

class UForceStrikeHealthComponent;
class UTextRenderComponent;

UCLASS()
class FORCESTRIKE_API AFirstCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstCharacter(const FObjectInitializer& ObjInit);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float DefaultSpeedCharacter = 600.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UForceStrikeHealthComponent *HealthComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent *HealthTextComponent;
	

  public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
    bool IsRunning() const;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;
    

  private:
    bool SprintButtomPressed = false;
    bool CanBeRunning = false;
    bool IsMovingForward = false;

	void OnStartSprint();
    void OnStopSprint();

	void MoveForward(float Axis);
    void MoveLeft(float Axis);
    
};
