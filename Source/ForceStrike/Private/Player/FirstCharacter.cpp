// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FirstCharacter.h"
#include "Components/MyCharacterMovementComponent.h"
#include "Components/ForceStrikeHealthComponent.h"

#include "Components/ForceStrikeHealthComponent.h"
#include "Components/TextRenderComponent.h"


// Sets default values
AFirstCharacter::AFirstCharacter(const FObjectInitializer &ObjInit): 
    Super(ObjInit.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
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

    HealthComponent = CreateDefaultSubobject<UForceStrikeHealthComponent>("HealthComponent");
    

    HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
    HealthTextComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AFirstCharacter::BeginPlay()
{
	Super::BeginPlay();
    GetCharacterMovement()->MaxWalkSpeed = DefaultSpeedCharacter;
    HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), HealthComponent->GetHealth())));
}



// Called every frame
void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    //const auto Health = HealthComponent->GetHealth();

}

// Called to bind functionality to input
void AFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &AFirstCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveLeft", this, &AFirstCharacter::MoveLeft);
    PlayerInputComponent->BindAxis("MouseUD", this, &AFirstCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("MouseLR", this, &AFirstCharacter::AddControllerYawInput);
    
    //PlayerInputComponent->BindAxis("Sprint", this, &AFirstCharacter::Sprint);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstCharacter::Jump);
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFirstCharacter::OnStartSprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFirstCharacter::OnStopSprint);

    
}


void AFirstCharacter::MoveForward(float Axis)
{
    //UE_LOG(LogTemp, Warning, TEXT("Move Forward: %f"), Axis)
    
    IsMovingForward = Axis > 0.0f;
    if(Axis==0.0f) return; 
    AddMovementInput(GetActorForwardVector(), Axis, false);

}

void AFirstCharacter::MoveLeft(float Axis)
{
    
    if(Axis==0.0f) return; 
    AddMovementInput(GetActorRightVector(), Axis, false);
}


void AFirstCharacter::OnStartSprint()
{
    CanBeRunning = true;
    
}

void AFirstCharacter::OnStopSprint()
{
    CanBeRunning = false;
}

bool AFirstCharacter::IsRunning() const
{
    return IsMovingForward && CanBeRunning && !GetVelocity().IsZero();
}

float AFirstCharacter::GetMovementDirection() const
{
    if (GetVelocity().IsZero()) return 0.0f;
    const auto VelocityNormal = GetVelocity().GetSafeNormal();
    const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(),VelocityNormal));
    const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(),VelocityNormal);
    const auto Degrees = FMath::RadiansToDegrees(AngleBetween);
    return CrossProduct.IsZero()? Degrees:Degrees*FMath::Sign(CrossProduct.Z);
    
}

