#include "GAS/GE/DecreaseTEST.h"
#include "Global.h"
#include "GAS/Attribute/CCharacterAttributeSet.h"

UDecreaseTEST::UDecreaseTEST()
{
    // ���� �ð� ��å (Duration Policy)
    DurationPolicy = EGameplayEffectDurationType::Instant;

    // Modifier ����
    FGameplayModifierInfo ModifierInfo;
    ModifierInfo.Attribute = UCCharacterAttributeSet::GetBaseStaminaAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Additive;
    ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(-5.f);
    Modifiers.Add(ModifierInfo);

    // �ߵ� Ȯ�� (Chance to Apply to Target)
    ChanceToApplyToTarget.SetValue(1.0f); // 100% ����

    // �ֱ��� ���� ��å (Periodic Inhibition Policy)
    // PeriodicInhibitionPolicy = EGameplayEffectPeriodInhibitionPolicy::NeverReset;

    // ���÷��� �ɼ� (Display Options)
    bRequireModifierSuccessToTriggerCues = true;
    bSuppressStackingCues = false;
}