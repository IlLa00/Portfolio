#include "AI_Dead.h"
#include "Global.h"
#include "Pet/CPet.h"
#include "DataAsset/CPetDataAsset.h"
#include "Enemy/CMonster.h"
#include "Enemy/CBoss.h"
#include "DataAsset/CMonsterMeshDataAsset.h"
#include "Item/CItem_HealBuff.h"
#include "Components/ShapeComponent.h"
#include "DataAsset/CMonsterMeshDataAsset.h"
#include "DataAsset/CBossDataAsset.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/CharacterMovementComponent.h"

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
	else if (OwnerInfo->AvatarActor->IsA<ACMonster>())
	{
		ACMonster* Monster = Cast<ACMonster>(OwnerInfo->AvatarActor);
		if (Monster)
		{
			if (Monster->GetDataAsset())
			{
				PrintLine();
				MontageToPlay = Monster->GetDataAsset()->Datas[Monster->GetIndex()].MontageDatas.DeadMontage;
				Dead(Monster); 
			}
		}
	}
	else if (OwnerInfo->AvatarActor->IsA<ACBoss>())
	{
		ACBoss* Boss = Cast<ACBoss>(OwnerInfo->AvatarActor);
		if (Boss)
		{
			if (Boss->GetBossDataAsset())
			{
				PrintLine();
				MontageToPlay = Boss->GetBossDataAsset()->MontageDatas.DeadMontage;
				Dead(Boss);
			}
		}
	}

	Super::ActivateAbility(Handle, OwnerInfo, ActivationInfo, TriggerEventData);
}

void UAI_Dead::Dead(ACharacter* Character)
{
	// �̷��� �з��ϴ°� ��������� �������̽� ����������
	if (Character->IsA<ACMonster>())
	{
		ACMonster* Monster = Cast<ACMonster>(Character);
		CheckNull(Monster);

		Monster->GetController()->UnPossess(); // �̰ɷ� ����������Ʈ �Ȳ����� ĳ��Ʈ����. ��Ʈ�ѷ� �������ؾ������ʳ�?

		TArray<UShapeComponent*> OutComps;
		Monster->GetComponents<UShapeComponent>(OutComps);

		for (const auto& Comp : OutComps)
		{
			Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}

		FTransform FT;
		FT.SetLocation(Monster->GetActorLocation());
		FT.SetRotation(FQuat());

		GetWorld()->SpawnActor<ACItem>(Monster->GetDataAsset()->Datas[Monster->GetIndex()].DropItem, FT);
	}
	else if (Character->IsA<ACBoss>())
	{
		ACBoss* Boss = Cast<ACBoss>(Character);
		CheckNull(Boss);

		Boss->GetController()->UnPossess(); // �̰ɷ� ����������Ʈ �Ȳ����� ĳ��Ʈ����. ��Ʈ�ѷ� �������ؾ������ʳ�?
		
		Boss->GetComponentByClass<UFloatingPawnMovement>()->SetActive(false);
		// Boss->GetComponentByClass<UCharacterMovementComponent>()->SetActive(false);

		Boss->GetMesh()->SetSimulatePhysics(true);

		//FTransform FT;
		//FT.SetLocation(Boss->GetActorLocation());
		//FT.SetRotation(FQuat());

		//GetWorld()->SpawnActor<ACItem>(Monster->GetDataAsset()->Datas[Monster->GetIndex()].DropItem, FT);
	}
	
	// ���õ� ���� <- ���õ� �����ϴ°� ������ ���̰� �ϱ�
	// �������� �״�� �ΰ� ����Ʈ���� �Լ��� ���ϴ°ɷ�?
}
