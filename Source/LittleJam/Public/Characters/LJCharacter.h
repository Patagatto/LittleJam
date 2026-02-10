// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "LJCharacter.generated.h"

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
	
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	//UStaticMeshComponent* Body;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* LookAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* JumpAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* ShootAction;
	
	
	UFUNCTION(BlueprintCallable)
	void Move(FVector2D Value);
	
	UFUNCTION(BlueprintCallable)
	void Look(FVector2D Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
