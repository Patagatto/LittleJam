// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LJCamera.h"

#include "Camera/CameraComponent.h"
#include "Customizations/MathStructProxyCustomizations.h"


// Sets default values
ALJCamera::ALJCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);

	// Default Settings
	FixedCameraRotation = FRotator(-90.0f, 0.0f, 00.0f);
}

// Called when the game starts or when spawned
void ALJCamera::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorRotation(FixedCameraRotation);
	SetActorLocation(FVector(0.0f, 0.0f, 800.0f));
}

// Called every frame
void ALJCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

