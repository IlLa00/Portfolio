#include "CProjectile.h"
#include "Global.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "AbilitySystemComponent.h"
#include "Player/CPlayer.h"
#include "Enemy/CEnemy.h"
#include "GAS/Attribute/CMonsterAttributeSet.h"
#include "Pet/CPet.h"
#include "GAS/Attribute/CPetAttributeSet.h"
#include "Interface/CAIInterface.h"
#include "GAS/Attribute/CAIAttributeSet.h"

ACProjectile::ACProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateSceneComponent(this, &RootComp, "RootComp");
	CheckNull(RootComp);

	CHelpers::CreateSceneComponent(this, &ParticleComp, "ParticleComp", RootComp);
	CheckNull(ParticleComp);

	CHelpers::CreateSceneComponent(this, &BoxComp, "BoxComp", RootComp);
	CheckNull(BoxComp);

	CHelpers::CreateActorComponent(this, &ProjectileComp, "ProjectileComp");
	CheckNull(ProjectileComp);
}

void ACProjectile::BeginPlay()
{
	Super::BeginPlay();

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ACProjectile::OnBoxBeginOverlap);
}

void ACProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACProjectile::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ���⼭ �ε��� ���� �ǰ� ��ƼŬ �߰� + ���� ���� + (���� �߰�)

	if (OtherActor->IsA<ACPlayer>()) // ��üũ ���� �� �߰��ؾ��ҰŰ���
		return;

	if (GetOwner()->IsA<ACPet>())
	{
		ACPet* Pet = Cast<ACPet>(GetOwner());
		CheckNull(Pet);	

		ICAIInterface* AI = Cast<ICAIInterface>(OtherActor);
		CheckNull(AI);

		AI->GetAIAttributeSet()->SetCurrentHealth(AI->GetAIAttributeSet()->GetCurrentHealth() - Pet->GetAttributeSet()->GetCurrentDamage());
		// ���⵵ �� �����ؼ� �պ����ҵ�
	}

	Destroy();
}

