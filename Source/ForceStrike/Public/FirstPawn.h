// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "FirstPawn.generated.h"



// TEST12

UCLASS()
class FORCESTRIKE_API AFirstPawn : public APawn
{
    GENERATED_BODY()

  public:
    // Sets default values for this pawn's properties
    AFirstPawn();

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent *Mesh;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    USpringArmComponent *SpringArm;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCameraComponent *Camera;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
    class UFloatingPawnMovement *PawnMovementComponent;

    UPROPERTY(BlueprintReadWrite, EditAnyWhere)
    USkeletalMeshComponent *SkeletalMesh;

    /*UPROPERTY(EditAnywhere)
    UCapsuleComponent* CapsuleComponent;
*/

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    // Control *mouse/keyboard*
    void MoveForward(float Axis);
    void MoveLeft(float Axis);

    void MouseUD(float Axis);
    void MouseLR(float Axis);
};
