// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/LJBulletSpawner.h"
#include "LJBulletSpawnerAlt.generated.h"

/**
 * 
 */
UENUM()
enum EShootingType
{
	Single UMETA(DisplayName="Single"),
	Triple UMETA(DisplayName="Triple"),
	Circle UMETA(DisplayName="Circle"),
};

UCLASS()
class LITTLEJAM_API ALJBulletSpawnerAlt : public ALJBulletSpawner
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ALJBulletSpawnerAlt();
	
protected:
	/* ----- Properties ----- */
	
	// Actor properties
	EShootingType ShootingType;
	
	// Rotation properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	float RotSpeed;
	
	float RotOffset;
	
	/* ----- Functions ----- */
	virtual void BeginPlay() override;
	
public:	
	// Functions
	virtual void Tick(float DeltaTime) override;
	
	virtual void InitializeSpawner() override;
	
	virtual void DeactivateSpawner() override;
	
	virtual void SpawnBullet() override;
	
	virtual void UpgradeDifficulty() override;
};
