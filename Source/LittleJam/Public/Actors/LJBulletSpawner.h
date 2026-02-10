// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Components/MeshComponent.h"
#include "Components/SceneComponent.h"
#include "Game/LJGamemode.h"
#include "GameFramework/Actor.h"
#include "LJBulletSpawner.generated.h"

UCLASS()
class LITTLEJAM_API ALJBulletSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ALJBulletSpawner();

protected:
	/* ----- Properties ----- */
	// Actor properties
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootSceneComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* BulletSpawnComp;
	
	UPROPERTY()
	FVector SpawnLocation;
	
	UPROPERTY()
	ALJGamemode* LJGamemode;
	
	// Locomotion properties
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USplineComponent* MovementSpline;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	bool CanMove = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	float MoveSpeed;
	
	float Direction = 1.0f;
	
	// Spawn properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	float InitSpawnRate = 2.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	float OffsetRate;
	
	float CurrSpawnRate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	float MinSpawnRate = 0.5f;
		
	FTimerHandle BulletTimer;
	
	/* ----- Functions ----- */
	virtual void BeginPlay() override;

public:	
	// Functions
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void InitializeSpawner();
	
	UFUNCTION(BlueprintCallable)
	virtual void DeactivateSpawner();
	
	UFUNCTION()
	virtual void SpawnBullet();
	
	UFUNCTION()
	virtual void UpgradeDifficulty();

};
