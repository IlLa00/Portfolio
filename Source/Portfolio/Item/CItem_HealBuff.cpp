#include "CItem_HealBuff.h"
#include "Global.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

ACItem_HealBuff::ACItem_HealBuff()
{

}

void ACItem_HealBuff::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PrintLine(); // �ߵ��� ���� ��Ʈ����Ʈ �����ϸ��.

	// ���� ��󿡰� ��ƼŬ ���
	if(SpawnParticle)
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), SpawnParticle, OtherActor->GetActorLocation());

	Destroy();
}
