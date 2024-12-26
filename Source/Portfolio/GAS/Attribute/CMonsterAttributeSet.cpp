#include "CMonsterAttributeSet.h"
#include "Global.h"
#include "Enemy/CEnemy.h"
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
	ACEnemy* Enemy = Cast<ACEnemy>(GetOwningActor());
	CheckNull(Enemy);

	if (NewValue <= 0.f) // �׾�����
	{
		TagHelpers::AIChangeStateTag(Enemy->GetTagContainer(), "AI.Action.Dead");
	}

	if (OldValue > NewValue) // ü���� ����������
	{
		TagHelpers::AIChangeStateTag(Enemy->GetTagContainer(), "AI.Action.GetHit");

		Enemy->GetHealthWidget()->Update(NewValue, GetBaseHealth()); // ��������Ʈ�� �غ���.
	}
}

void UCMonsterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
