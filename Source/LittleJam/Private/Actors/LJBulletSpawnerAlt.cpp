// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LJBulletSpawnerAlt.h"

ALJBulletSpawnerAlt::ALJBulletSpawnerAlt()
{
	ShootingType = Single;
}

void ALJBulletSpawnerAlt::BeginPlay()
{
	Super::BeginPlay();
}

void ALJBulletSpawnerAlt::Tick(float DeltaTime)
{
	if (CanMove) Super::Tick(DeltaTime);
	
	// Rotation logic
	if (RotOffset >= 360.0f) RotOffset = 0.0f;
	
	RotOffset += DeltaTime * RotSpeed;
	SetActorRotation(FRotator(0.0f, RotOffset, 0.0f));
}

void ALJBulletSpawnerAlt::InitializeSpawner()
{
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	
	GetWorld()->GetTimerManager().SetTimer(BulletTimer, this, &ALJBulletSpawner::SpawnBullet, CurrSpawnRate, true);
}

void ALJBulletSpawnerAlt::DeactivateSpawner()
{
	Super::DeactivateSpawner();
	
}

void ALJBulletSpawnerAlt::SpawnBullet()
{
	switch (ShootingType)
	{
	case (Single):
		Super::SpawnBullet();
		break;
			
	case (Triple):
		
		break;
		
	case Circle:
		break;
	}
}

void ALJBulletSpawnerAlt::UpgradeDifficulty()
{
	Super::UpgradeDifficulty();
	
	if (CurrSpawnRate <= MinSpawnRate && ShootingType != Circle)
	{
		CurrSpawnRate = InitSpawnRate;
		
		switch (ShootingType)
		{
		case (Single):
			ShootingType = Triple;
			break;
			
		case (Triple):
			ShootingType = Circle;
			break;
		
		case Circle:
			break;
		}
	}
}
