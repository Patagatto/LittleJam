// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LJCamera.h"

#include "LJLifeComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/LJCharacter.h"


// Sets default values
ALJCamera::ALJCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
	
	HearthContainer = CreateDefaultSubobject<USceneComponent>(TEXT("Hearth Container"));
	HearthContainer->SetupAttachment(CameraComponent);
	
	HearthContainer->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	float Spacing = 45.0f;

	for (int i = 0; i < 3; i++)
	{
		FString HearthName = FString::Printf(TEXT("HearthMesh_%d"), i);
		UStaticMeshComponent* NewHearth = CreateDefaultSubobject<UStaticMeshComponent>(*HearthName);
		NewHearth->SetupAttachment(HearthContainer);
		
		float YPos = (i -2) * Spacing;
		
		NewHearth->SetRelativeLocation(FVector(0.0f, YPos, 0.0f));
		
		NewHearth->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		NewHearth->SetCastContactShadow(false);
		NewHearth->SetRelativeScale3D(FVector(0.3f));
		NewHearth->SetMaterial(0, CubeMaterial);
		
		HearthMeshes.Add(NewHearth);
		
	}

	// Default Settings
	FixedCameraRotation = FRotator(-90.0f, 0.0f, 00.0f);
}

// Called when the game starts or when spawned
void ALJCamera::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorRotation(FixedCameraRotation);
	SetActorLocation(FVector(0.0f, 0.0f, 1200.0f));
	
	BindToHealthComponent();
}

void ALJCamera::UpdateHealth(int32 CurrentHealth)
{
	if (!SphereMesh) return;

	for (int i = 0; i < HearthMeshes.Num(); ++i)
	{
		if (i < CurrentHealth)
		{
				HearthMeshes[i]->SetStaticMesh(CubeMesh);
				HearthMeshes[i]->SetMaterial(0, CubeMaterial);
		}
		else
		{
			HearthMeshes[i]->SetStaticMesh(SphereMesh);
			HearthMeshes[i]->SetMaterial(0, SphereMaterial);
		}
		
		
	}
}

void ALJCamera::BindToHealthComponent()
{
	if (ALJCharacter* Character = Cast<ALJCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		ULJLifeComponent* LifeComponent = Character->GetComponentByClass<ULJLifeComponent>();

		if (LifeComponent)
		{
			LifeComponent->HealthUpdate.AddDynamic(this, &ALJCamera::UpdateHealth);
		}
	}
	else
	{
		GetWorldTimerManager().SetTimer(HealthTimerHandle, this, &ALJCamera::BindToHealthComponent, 0.1f, false);
	}
}

// Called every frame
void ALJCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

