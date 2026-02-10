#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LJLifeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LITTLEJAM_API ULJLifeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULJLifeComponent();

	UFUNCTION(BlueprintCallable)
	bool ApplyDamage(float Amount);
	
	UPROPERTY(EditAnywhere)
	int MaxHealth;

	UPROPERTY(VisibleAnywhere)
	int CurrentHealth;
	
	UPROPERTY(VisibleAnywhere)
	bool IsDead= false;
protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
