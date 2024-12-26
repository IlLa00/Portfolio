#include "AI_Dead.h"
#include "Global.h"
#include "Pet/CPet.h"
#include "DataAsset/CPetDataAsset.h"
#include "Enemy/CEnemy.h"
#include "DataAsset/CMonsterMeshDataAsset.h"
#include "Item/CItem_HealBuff.h"
#include "Components/ShapeComponent.h"
#include "DataAsset/CMonsterMeshDataAsset.h"

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
		ACEnemy* Enemy = Cast<ACEnemy>(Character);
		CheckNull(Enemy);

		Enemy->GetController()->UnPossess(); // �̰ɷ� ����������Ʈ �Ȳ����� ĳ��Ʈ����. ��Ʈ�ѷ� �������ؾ������ʳ�?

		TArray<UShapeComponent*> OutComps;
		Enemy->GetComponents<UShapeComponent>(OutComps);

		for (const auto& Comp : OutComps)
		{
			Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}

		FTransform FT;
		FT.SetLocation(Enemy->GetActorLocation());
		FT.SetRotation(FQuat());

		GetWorld()->SpawnActor<ACItem>(Enemy->GetDataAsset()->Datas[Enemy->GetIndex()].DropItem, FT);
		// GetWorld()->SpawnActor<ACItem>(Enemy->GetActorLocation(), FRotator()); // �������ڸ� �������� ȣ��Ǿ���� �׷��� �̰� ������ �ݸ������ߵ�

	}
	
	// ���õ� ���� <- ���õ� �����ϴ°� ������ ���̰� �ϱ�
	// �������� �״�� �ΰ� ����Ʈ���� �Լ��� ���ϴ°ɷ�?
}
