// Fill out your copyright notice in the Description page of Project Settings.


#include "LJLifeComponent.h"

// Sets default values for this component's properties
ULJLifeComponent::ULJLifeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool ULJLifeComponent::ApplyDamage(float Amount)
{
	//Dentro un if alla fine di qualsiasi cosa che facciamo ci deve essere TRUE o FALSE
	if (IsDead)
	{
		return false;
	}

	//Questo metodo si occupa solo di TOGLIERE vita. Non ne pu� aggiungere.
	if (Amount <= 0)
	{
		return false;
	}

	//Questo � equivalente a CurrentHealth = CurrentHealth - Amount;
	CurrentHealth -= Amount;

	if (CurrentHealth <= 0)
	{
		IsDead = true;

	}

	return true;
}


// Called when the game starts
void ULJLifeComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	// ...
	
}


// Called every frame
void ULJLifeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

