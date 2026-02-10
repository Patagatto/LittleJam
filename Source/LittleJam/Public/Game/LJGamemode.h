// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LJGamemode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpgradeTimeReached);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeUpdated, float, NewTime);
/**
 * 
 */
UCLASS(Abstract)
class LITTLEJAM_API ALJGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ALJGamemode();
	
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;
	
	FOnUpgradeTimeReached OnUpgradeTimeReached;
	
	FOnTimeUpdated OnTimeUpdated;
protected:
	
	
	float ElapsedTime = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UpgradeTime = 30.0f;
	
	FTimerHandle UpgradeTimerHandle;
	
	UFUNCTION()
	void UpgradeDifficulty();
	
	void AssignCamera(APlayerController* Controller);
};
