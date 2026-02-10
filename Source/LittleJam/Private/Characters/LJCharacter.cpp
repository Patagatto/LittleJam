// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Characters/LJCharacter.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"

#include "LJLifeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


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
	
	Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	Cube->SetupAttachment(GetMesh());
	
	LifeComp = CreateDefaultSubobject<ULJLifeComponent>("LifeComp");
	
	
	
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
			UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->GetComponentByClass<UEnhancedInputComponent>());
			EnhancedInputComponent->BindAction(RestartAction, ETriggerEvent::Started, this, &ALJCharacter::RestartLevel);
		}
	}
			
	DynamicMaterialInstance = Cube->CreateDynamicMaterialInstance(0);
	DynamicMaterialInstance->SetVectorParameterValue("Color", FLinearColor(0.0f, 0.01f, 0.0f, 0.3f));
		
	if (LifeComp)
	{
		LifeComp->HealthUpdate.AddDynamic(this, &ALJCharacter::ActivateHit);
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

void ALJCharacter::RestartLevel()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (PlayerController->IsPaused())
		{
			FName LevelName(UGameplayStatics::GetCurrentLevelName(GetWorld()));
			UGameplayStatics::OpenLevel(GetWorld(), LevelName);
		}
	}
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

void ALJCharacter::ActivateHit(int32 Value)
{
	DynamicMaterialInstance->SetVectorParameterValue("Color", FLinearColor(1.0f, 1.0f, 1.0f, 0.3f));

	if (!GetWorld()->GetTimerManager().IsTimerActive(HitTimer))
	{
		GetWorld()->GetTimerManager().SetTimer(HitTimer, this, &ALJCharacter::DeactivateHit, 0.5f, false);
	}
}

void ALJCharacter::DeactivateHit()
{
	DynamicMaterialInstance->SetVectorParameterValue("Color", FLinearColor(0.0f, 0.01f, 0.0f, 0.3f));
}


