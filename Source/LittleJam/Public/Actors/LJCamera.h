// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "LJCamera.generated.h"

UCLASS()
class LITTLEJAM_API ALJCamera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALJCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	class USceneComponent* HearthContainer;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ui")
	UStaticMesh* CubeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ui")
	UMaterialInterface* CubeMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ui")
	UMaterialInterface* SphereMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ui")
	UStaticMesh* SphereMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TArray<class UStaticMeshComponent*> HearthMeshes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	FRotator FixedCameraRotation;

	/** Base distance from the centroid of players. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	float BaseDistance;
	
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void UpdateHealth(int32 CurrentHealth);

	void BindToHealthComponent();
	
	FTimerHandle HealthTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
