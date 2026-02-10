// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class LITTLEJAM_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
	
	public:
		virtual void NativeConstruct() override;
	
	UFUNCTION()
	void UpdateTime(float NewTime);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TimerTextBlock;

};
