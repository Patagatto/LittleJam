// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BulletActor.h"

#include "LJLifeComponent.h"
#include "DataWrappers/ChaosVDParticleDataWrapper.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	RootSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComp);
	
	BulletBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BulletBox->SetupAttachment(RootSceneComp);
	BulletBox->SetWorldScale3D(FVector(0.3f));
	BulletBox->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::NotifyOverlapping);

}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
		
	GetWorld()->GetTimerManager().SetTimer(LifeTimer, this, &ABulletActor::OnDestroyActor, LifeSpan, false);
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(GetActorLocation() + (GetActorForwardVector()* MoveSpeed * DeltaTime));

}

void ABulletActor::NotifyOverlapping(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	if (!OtherActor || !PlayerChar || OtherActor != PlayerChar) return;

	if (ULJLifeComponent* LifeComp = OtherActor->GetComponentByClass<ULJLifeComponent>())
	{
		LifeComp->ApplyDamage(1);
		OnDestroyActor();
	}
}

void ABulletActor::OnDestroyActor()
{
	Destroy();
}

