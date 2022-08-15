// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPawn.h"



// Sets default values
AFirstPawn::AFirstPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	
	
	//Create Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetRelativeLocation(FVector(-120.0f, 0.0f, 214.0f));
	Camera->SetRelativeRotation(FRotator(-21.0f, 0.0f, 0.0f));
	Camera->bUsePawnControlRotation = true;
	
	//Create SkeletalMesh
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletanMesh");
	SkeletalMesh->SetRelativeLocation(FVector(200.0f, 0.0f, 0.0f ));
	SkeletalMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));	
	
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;


	SpringArm->SetupAttachment(Mesh);
	SkeletalMesh->SetupAttachment(SpringArm);
	Camera->SetupAttachment(SpringArm);
	

	PawnMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovementComponent");



}

// Called when the game starts or when spawned
void AFirstPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



// Called to bind functionality to input
void AFirstPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AFirstPawn::MoveLeft);
	PlayerInputComponent->BindAxis("MouseUD", this, &AFirstPawn::MouseUD);
	PlayerInputComponent->BindAxis("MouseLR", this, &AFirstPawn::MouseLR);
}

void AFirstPawn::MoveForward(float Axis) 
{
	UE_LOG(LogTemp, Warning, TEXT("Move forward: %f"), Axis)
	AddMovementInput(GetActorForwardVector(), Axis, false);
}

void AFirstPawn::MoveLeft(float Axis) 
{
	UE_LOG(LogTemp, Warning, TEXT("Move left/right: %f"), Axis)
	AddMovementInput(GetActorRightVector(), Axis, false);
}

void AFirstPawn::MouseUD(float Axis)
{
	AddControllerPitchInput(-Axis);
}

void AFirstPawn::MouseLR(float Axis)
{
	AddControllerYawInput(Axis);
}
