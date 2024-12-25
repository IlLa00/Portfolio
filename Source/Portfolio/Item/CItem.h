#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CItem.generated.h"

class UBoxComponent;
class UNiagaraComponent;

UCLASS()
class PORTFOLIO_API ACItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ACItem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Component")
		USceneComponent* RootComp;

	UPROPERTY(EditDefaultsOnly, Category = "Component")
		UBoxComponent* BoxComp;

	UPROPERTY(EditDefaultsOnly, Category = "Component")
		UNiagaraComponent* ParticleComp;

};