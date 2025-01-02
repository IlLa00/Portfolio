#include "CAIAttributeSet.h"
#include "Global.h"
#include "Interface/CAIInterface.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "Widget/CEnemyHealthWidget.h"
#include "Widget/CBossWidget.h"
#include "Enemy/CMonster.h"
#include "Enemy/CBoss.h"
#include "Pet/CPet.h"
#include "Widget/CPetWidget.h"

void UCAIAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

}

void UCAIAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	ICAIInterface* AI = Cast<ICAIInterface>(GetOwningActor()); 
	CheckNull(AI);

	if (NewValue <= 0.f) // �׾�����
	{
		TagHelpers::AIChangeStateTag(AI->GetTagContainer(), "AI.Action.Dead");
	}

	if (OldValue > NewValue) // ü���� ����������
	{
		if (GetOwningActor()->IsA<ACMonster>())
		{
			TagHelpers::AIChangeStateTag(AI->GetTagContainer(), "AI.Action.GetHit");

			ACMonster* Monster = Cast<ACMonster>(GetOwningActor());
			CheckNull(Monster);

			Monster->GetHealthWidget()->Update(NewValue, GetBaseHealth());
		}
		else if (GetOwningActor()->IsA<ACBoss>())
		{
			ACBoss* Boss = Cast<ACBoss>(GetOwningActor());
			CheckNull(Boss);
			CheckNull(Boss->GetHealthWidget());

			Boss->GetHealthWidget()->Update(NewValue, GetBaseHealth());
		}
		else if (GetOwningActor()->IsA<ACPet>())
		{
			ACPet* Pet = Cast<ACPet>(GetOwningActor());
			CheckNull(Pet);
			CheckNull(Pet->GetHealthWidget());

			Pet->GetHealthWidget()->Update(NewValue, GetBaseHealth());
		}
	}
}
