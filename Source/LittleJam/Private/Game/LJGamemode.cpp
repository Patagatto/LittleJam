// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Game/LJGamemode.h"

#include "Actors/LJCamera.h"
#include "Kismet/GameplayStatics.h"

ALJGamemode::ALJGamemode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALJGamemode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(UpgradeTimerHandle, this, &ALJGamemode::UpgradeDifficulty, UpgradeTime, true);
	if (APlayerController* Controller = GetWorld()->GetFirstPlayerController())
	{
		AssignCamera(Controller);
	}	
}

void ALJGamemode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ElapsedTime += DeltaTime;
	
	OnTimeUpdated.Broadcast(ElapsedTime);
}

void ALJGamemode::UpgradeDifficulty()
{
	OnUpgradeTimeReached.Broadcast();
}

void ALJGamemode::AssignCamera(APlayerController* Controller)
{
	if (!Controller) return;

	// Locate the Shared Camera actor in the level
	if (AActor* SharedCam = UGameplayStatics::GetActorOfClass(this, ALJCamera::StaticClass()))
	{
		Controller->SetViewTargetWithBlend(SharedCam);
		UE_LOG(LogTemp, Log, TEXT("AssignSharedCamera: Assigned SharedCamera to %s"), *Controller->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AssignSharedCamera: No ASharedCamera found in the level!"));
	}
}
