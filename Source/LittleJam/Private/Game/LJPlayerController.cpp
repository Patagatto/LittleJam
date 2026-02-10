// Fill out your copyright notice in the Description page of Project Settings.


#include "LittleJam/Public/Game/LJPlayerController.h"

#include "Blueprint/UserWidget.h"

void ALJPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetClass)
	{
		MyWidgetInstance = CreateWidget<UUserWidget>(this, WidgetClass);

		if (MyWidgetInstance)
		{
			MyWidgetInstance->AddToViewport();
		}
	}
}
