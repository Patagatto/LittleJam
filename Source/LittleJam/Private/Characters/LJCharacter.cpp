// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Characters/LJCharacter.h"


// Sets default values
ALJCharacter::ALJCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALJCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

