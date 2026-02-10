// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LJBulletSpawner.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ALJBulletSpawner::ALJBulletSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	CurrSpawnRate = InitSpawnRate;
	
	RootSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComp);
    
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootSceneComp);
    
    BulletSpawnComp = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnComp"));
    BulletSpawnComp->SetupAttachment(MeshComp);
	
	MovementSpline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComp"));
	MovementSpline->SetupAttachment(RootSceneComp);
}

// Called when the game starts or when spawned
void ALJBulletSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLocation = GetActorLocation();
	
	LJGamemode = Cast<ALJGamemode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (LJGamemode) LJGamemode->OnUpgradeTimeReached.AddDynamic(this, &ALJBulletSpawner::UpgradeDifficulty);
	
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ALJBulletSpawner::InitializeSpawner, 1.5f, false);
}

// Called every frame
void ALJBulletSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Movement logic
}

void ALJBulletSpawner::InitializeSpawner()
{
	SetActorHiddenInGame(false);
	if (CanMove) SetActorTickEnabled(true);
	
	GetWorld()->GetTimerManager().SetTimer(BulletTimer, this, &ALJBulletSpawner::SpawnBullet, CurrSpawnRate, true);
}

void ALJBulletSpawner::DeactivateSpawner()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	
	GetWorld()->GetTimerManager().ClearTimer(BulletTimer);
	CurrSpawnRate = InitSpawnRate;
	
	SetActorLocation(SpawnLocation);
}

void ALJBulletSpawner::SpawnBullet()
{
	if (BulletClass)
	{
		AActor* BulletTempActor = GetWorld()->SpawnActor(BulletClass);
		if (BulletTempActor)
		{
			BulletTempActor->SetActorLocation(BulletSpawnComp->GetComponentLocation());
			BulletTempActor->SetActorRotation(BulletSpawnComp->GetComponentRotation());
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Spawning Bullet"));
}

void ALJBulletSpawner::UpgradeDifficulty()
{
	if (CurrSpawnRate > MinSpawnRate)
	{
		GetWorld()->GetTimerManager().ClearTimer(BulletTimer);
		CurrSpawnRate = FMath::Clamp(CurrSpawnRate - OffsetRate, MinSpawnRate, InitSpawnRate);
		GetWorld()->GetTimerManager().SetTimer(BulletTimer, this, &ALJBulletSpawner::SpawnBullet, CurrSpawnRate, true);
	}
}

