// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "LJCharacter.generated.h"

class ULJLifeComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS(Abstract)
class LITTLEJAM_API ALJCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALJCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* LookAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* RestartAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* ShootAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	UStaticMeshComponent* Cube;
	
	UPROPERTY(EditAnywhere, Category="Material")
	UMaterialInstanceDynamic* DynamicMaterialInstance;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Component")
	ULJLifeComponent* LifeComp;
	
	UFUNCTION(BlueprintCallable)
	void Move(FVector2D Value);
	
	UFUNCTION(BlueprintCallable)
	void Look(FVector2D Value);

	FTimerHandle HitTimer;
	
	UFUNCTION()
	void ActivateHit(int32 Value);
	
	UFUNCTION()
	void DeactivateHit();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void RestartLevel();
};
