// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FirstCharacter.h"


// Sets default values
AFirstCharacter::AFirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Create SpringArm
    SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArm->SetupAttachment(GetRootComponent());
    SpringArm->bUsePawnControlRotation = true;

    //Camera Setting
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArm);

    
    
}

// Called when the game starts or when spawned
void AFirstCharacter::BeginPlay()
{
	Super::BeginPlay();
    GetCharacterMovement()->MaxWalkSpeed = DefaultSpeedCharacter;
}

// Called every frame
void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    

}

// Called to bind functionality to input
void AFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &AFirstCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveLeft", this, &AFirstCharacter::MoveLeft);
    PlayerInputComponent->BindAxis("MouseUD", this, &AFirstCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("MouseLR", this, &AFirstCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("Sprint", this, &AFirstCharacter::Sprint);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstCharacter::Jump);

    
}

void AFirstCharacter::MoveForward(float Axis)
{
    //UE_LOG(LogTemp, Warning, TEXT("Move Forward: %f"), Axis)
    AddMovementInput(GetActorForwardVector(), Axis, false);
}

void AFirstCharacter::MoveLeft(float Axis)
{
    //UE_LOG(LogTemp, Warning, TEXT("Move Left,Right: %f"), Axis)
    AddMovementInput(GetActorRightVector(), Axis, false);
}

void AFirstCharacter::Sprint(float SprintValue)
{
   
    SprintValue ? GetCharacterMovement()->MaxWalkSpeed = DefaultSpeedCharacter * 2
                : GetCharacterMovement()->MaxWalkSpeed = DefaultSpeedCharacter;
}



