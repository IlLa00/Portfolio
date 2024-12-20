#include "Sword.h"
#include "Global.h"
#include "Player/CPlayer.h"

USword::USword()
{
	CHelpers::GetAsset(&AttackMontageClasses[0], "/Game/Assets/Montage/Frank_RPG_Warrior_Combo01_1_Montage");
	CHelpers::GetAsset(&AttackMontageClasses[1], "/Game/Assets/Montage/Frank_RPG_Warrior_Combo01_2_Montage");
	CHelpers::GetAsset(&AttackMontageClasses[2], "/Game/Assets/Montage/Frank_RPG_Warrior_Combo01_3_Montage");
	CHelpers::GetAsset(&AttackMontageClasses[3], "/Game/Assets/Montage/Frank_RPG_Warrior_Combo01_4_Montage");
}

void USword::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ACPlayer* Player = Cast<ACPlayer>(ActorInfo->AvatarActor->GetOwner());
	CheckNull(Player);
	
	if (Player->GetCurrentMontage() == AttackMontageClasses[0])
	{
		Player->StopAnimMontage();
		Player->PlayAnimMontage(AttackMontageClasses[1]);
	}
	else if (Player->GetCurrentMontage() == AttackMontageClasses[1])
	{
		Player->StopAnimMontage();
		Player->PlayAnimMontage(AttackMontageClasses[2]);
	}
	else if (Player->GetCurrentMontage() == AttackMontageClasses[2])
	{
		Player->StopAnimMontage();
		Player->PlayAnimMontage(AttackMontageClasses[3]);
	}
	else
		Player->PlayAnimMontage(AttackMontageClasses[0]);
	
}

void USword::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);

	// ComboCount = 0; // 여기서 하는게 맞나?
}
