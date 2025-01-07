#include "GAS/GE/DecreaseTEST.h"

UDecreaseTEST::UDecreaseTEST()
{
    // ���� �ð� ��å (Duration Policy)
    DurationPolicy = EGameplayEffectDurationType::Instant;

    // Modifier ����
    FGameplayModifierInfo ModifierInfo;
    ModifierInfo.Attribute = UCharacterAttributeSet::GetCurrentStaminaAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Additive;
    ModifierInfo.Magnitude.SetMagnitude(EScalableFloatMagnitudeType::ScalableFloat, -5.0f); // ���¹̳� ���ҷ�
    Modifiers.Add(ModifierInfo);

    // �ߵ� Ȯ�� (Chance to Apply to Target)
    ChanceToApplyToTarget.SetValue(1.0f); // 100% ����

    // �ֱ��� ���� ��å (Periodic Inhibition Policy)
    PeriodicInhibitionPolicy = EGameplayEffectPeriodInhibitionPolicy::NeverReset;

    // ���÷��� �ɼ� (Display Options)
    bRequireModifierSuccessToTriggerCues = true;
    bSuppressStackingCues = false;
}