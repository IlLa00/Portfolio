#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CBTService_Pet.generated.h"


UCLASS()
class PORTFOLIO_API UCBTService_Pet : public UBTService
{
	GENERATED_BODY()

public:
	UCBTService_Pet();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
