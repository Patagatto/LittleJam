// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class LITTLEJAM_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	/* ----- Properties ----- */
	// Actor properties
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootSceneComp;
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBoxComponent* BulletBox;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float LifeSpan = 10.0f;
	
	FTimerHandle LifeTimer;
			
	// Locomotion properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	float MoveSpeed;
		
	/* ----- Functions ----- */
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void NotifyOverlapping(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	void OnDestroyActor();
};
