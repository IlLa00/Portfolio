#include "CMonsterAttributeSet.h"
#include "Global.h"
#include "Enemy/CMonster.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "Widget/CEnemyHealthWidget.h"

UCMonsterAttributeSet::UCMonsterAttributeSet()
{

}

void UCMonsterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

}

void UCMonsterAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	//ACMonster* Monster = Cast<ACMonster>(GetOwningActor());
	//CheckNull(Monster);

	//if (NewValue <= 0.f) // �׾�����
	//{
	//	TagHelpers::AIChangeStateTag(Monster->GetTagContainer(), "AI.Action.Dead");
	//}

	//if (OldValue > NewValue) // ü���� ����������
	//{
	//	TagHelpers::AIChangeStateTag(Monster->GetTagContainer(), "AI.Action.GetHit");

	//	Monster->GetHealthWidget()->Update(NewValue, GetBaseHealth()); // ��������Ʈ�� �غ���.
	//}
}

void UCMonsterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
