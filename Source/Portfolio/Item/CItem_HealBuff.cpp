#include "CItem_HealBuff.h"
#include "Global.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

ACItem_HealBuff::ACItem_HealBuff()
{

}

void ACItem_HealBuff::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CLog::Print(OtherComp->GetName()); // �귯�� ������Ʈ�� �ε����µ� �̰Թ���???????????

	// ���� ��󿡰� ��ƼŬ ���
	if(SpawnParticle)
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), SpawnParticle, OtherActor->GetActorLocation());

	Destroy();
}
