#include "GAS/GE/TESTGameplayEffect.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "GAS/Attribute/CWeaponAttributeSet.h"

UTESTGameplayEffect::UTESTGameplayEffect()
{
    DurationPolicy = EGameplayEffectDurationType::HasDuration;
    DurationMagnitude = FGameplayEffectModifierMagnitude(10.0f);

    FGameplayModifierInfo Modifier;
    Modifier.Attribute = FGameplayAttribute(FindFieldChecked<FProperty>(
        UCWeaponAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCWeaponAttributeSet, CurrentDamage)
    ));

    Modifier.ModifierOp = EGameplayModOp::Additive;  // Add ���
    Modifier.ModifierMagnitude = FGameplayEffectModifierMagnitude(10.0f); // 10��ŭ �߰�

    Modifiers.Add(Modifier);
}
