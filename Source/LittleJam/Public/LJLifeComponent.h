#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LJLifeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthUpdate, int32, Health);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LITTLEJAM_API ULJLifeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULJLifeComponent();

	UFUNCTION(BlueprintCallable)
	bool ApplyDamage(int32 Amount);
	
	UPROPERTY(EditAnywhere)
	int32 MaxHealth = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentHealth = MaxHealth;
	
	UPROPERTY(VisibleAnywhere)
	bool IsDead= false;
	
	FHealthUpdate HealthUpdate;

protected:
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
