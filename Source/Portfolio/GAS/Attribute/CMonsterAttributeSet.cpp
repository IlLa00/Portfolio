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
	if (OldValue > NewValue) // ü���� ����������
	{
		ACEnemy* Enemy = Cast<ACEnemy>(GetOwningActor());
		if (Enemy)
		{
			TagHelpers::AIChangeStateTag(Enemy->GetTagContainer(), "AI.State.GetHit");

			Enemy->GetHealthWidget()->Update(NewValue, GetBaseHealth()); // ��������Ʈ�� �غ���.
		}
	}
}

void UCMonsterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
