// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Widgets/MainHUD.h"

#include "Components/TextBlock.h"
#include "Game/LJGamemode.h"
#include "Kismet/GameplayStatics.h"

void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	if (TimerTextBlock)
	{
		TimerTextBlock->SetText(FText::FromString("00:00"));
	}

	if (ALJGamemode* GM = Cast<ALJGamemode>(UGameplayStatics::GetGameMode(this)))
	{
		GM->OnTimeUpdated.AddDynamic(this, &UMainHUD::UpdateTime);
	}
}

void UMainHUD::UpdateTime(float NewTime)
{
	int32 Minutes = FMath::FloorToInt(NewTime / 60.0);
	int32 Seconds = FMath::FloorToInt(FMath::Fmod(NewTime, 60.0));
	
	FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	
	
	TimerTextBlock->SetText(FText::FromString(TimeString));
}
