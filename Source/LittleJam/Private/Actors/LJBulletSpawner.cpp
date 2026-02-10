// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LJBulletSpawner.h"

// Sets default values
ALJBulletSpawner::ALJBulletSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	CurrSpawnRate = InitSpawnRate;
    
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    
    BulletSpawnComp = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnComp"));
    BulletSpawnComp->SetupAttachment(MeshComp);
	
	MovementSpline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComp"));
	
}

// Called when the game starts or when spawned
void ALJBulletSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLocation = GetActorLocation();
}

// Called every frame
void ALJBulletSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ALJBulletSpawner::InitializeSpawner()
{
	GetWorld()->GetTimerManager().SetTimer(BulletTimer, this, &ALJBulletSpawner::SpawnBullet, CurrSpawnRate, true);
	if (CanMove) SetActorTickEnabled(true);
}

void ALJBulletSpawner::SpawnBullet()
{
	// Call the spawner subsystem and spawn the bullet using BulletSpawnComp location
	UE_LOG(LogTemp, Warning, TEXT("Spawning Bullet"));
}

void ALJBulletSpawner::UpgradeDifficulty()
{
	if (CurrSpawnRate < MaxSpawnRate)
	{
		CurrSpawnRate = FMath::Clamp(CurrSpawnRate - OffsetRate, MaxSpawnRate, InitSpawnRate);
	}
}

