// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Characters/LJCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ALJCharacter::ALJCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	
	
	
	//Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
}

// Called when the game starts or when spawned
void ALJCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// Get the enhanced input local player subsystem and add a new input mapping context to it
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void ALJCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALJCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ALJCharacter::Move(FVector2D Value)
{
	AddMovementInput(GetActorRightVector(), Value.X);
	AddMovementInput(GetActorForwardVector(), Value.Y);
}

void ALJCharacter::Look(FVector2D Value)
{
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}
