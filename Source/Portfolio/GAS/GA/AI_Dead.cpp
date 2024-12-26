#include "AI_Dead.h"
#include "Global.h"
#include "Pet/CPet.h"
#include "DataAsset/CPetDataAsset.h"
#include "Enemy/CEnemy.h"
#include "DataAsset/CMonsterMeshDataAsset.h"
#include "Item/CItem_HealBuff.h"
#include "Components/ShapeComponent.h"

void UAI_Dead::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (OwnerInfo->AvatarActor->IsA<ACPet>())
	{
		ACPet* Pet = Cast<ACPet>(OwnerInfo->AvatarActor);
		if (Pet)
		{
			if (Pet->GetDataAsset())
			{
				MontageToPlay = Pet->GetDataAsset()->MontageDatas.DeadMontage;
			}
		}
	}
	else if (OwnerInfo->AvatarActor->IsA<ACEnemy>())
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerInfo->AvatarActor);
		if (Enemy)
		{
			if (Enemy->GetDataAsset())
			{
				PrintLine();
				MontageToPlay = Enemy->GetDataAsset()->Datas[Enemy->GetIndex()].MontageDatas.DeadMontage;
				Dead(Enemy); // �ƹ������� �������̽��� �־��������?
			}
		}
	}

	Super::ActivateAbility(Handle, OwnerInfo, ActivationInfo, TriggerEventData);
}

void UAI_Dead::Dead(ACharacter* Character)
{
	// �̷��� �з��ϴ°� ��������� �������̽� ����������
	if (Character->IsA<ACEnemy>())
	{
		Character->GetController()->UnPossess(); // �̰ɷ� ����������Ʈ �Ȳ����� ĳ��Ʈ����. ��Ʈ�ѷ� �������ؾ������ʳ�?

		TArray<UShapeComponent*> OutComps;
		Character->GetComponents<UShapeComponent>(OutComps);

		for (const auto& Comp : OutComps)
		{
			Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}

		GetWorld()->SpawnActor<ACItem_HealBuff>(Character->GetActorLocation(), FRotator()); // �������ڸ� �������� ȣ��Ǿ���� �׷��� �̰� ������ �ݸ������ߵ�

	}
	
	// ���õ� ���� <- ���õ� �����ϴ°� ������ ���̰� �ϱ�
	// �������� �״�� �ΰ� ����Ʈ���� �Լ��� ���ϴ°ɷ�?
}
