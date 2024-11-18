#pragma once

#include "CoreMinimal.h"
#include "Enemy/CEnemy.h"
#include "CBoss.generated.h"

UCLASS()
class PORTFOLIO_API ACBoss : public ACEnemy
{
	GENERATED_BODY()
	
public:
	ACBoss();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "AnimClass")
		TSubclassOf<UAnimInstance> AnimClass;
};
