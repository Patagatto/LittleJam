// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LJPlayerController.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class LITTLEJAM_API ALJPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> WidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UUserWidget* MyWidgetInstance;
	
};
