// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Game/LJGamemode.h"

ALJGamemode::ALJGamemode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALJGamemode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(UpgradeTimerHandle, this, &ALJGamemode::UpgradeDifficulty, UpgradeTime, true);
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
