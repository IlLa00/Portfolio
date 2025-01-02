#include "CPlayerWidget.h"
#include "Global.h"
#include "Components/ProgressBar.h"
#include "Player/CPlayer.h"
#include "GAS/Attribute/CCharacterAttributeSet.h"
#include "Pet/CPet.h"
#include "GAS/Attribute/CAIAttributeSet.h"
#include "Components/EditableTextBox.h"
#include "Components/Image.h"

void UCPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ACPlayer* Player = Cast<ACPlayer>(GetOwningPlayerPawn());
	if (Player)
	{
		if (Player && Player->GetAbilitySystemComponent())
		{
			UpdateHealthBar(Player->GetAttributeSet()->GetCurrentHealth());
			UpdateStaminaBar(Player->GetAttributeSet()->GetCurrentStamina());
		}
	}

	if (Player->GetAttributeSet())
	{
		Player->GetAttributeSet()->OnHealthChanged.AddDynamic(this, &UCPlayerWidget::OnHealthChange);
		Player->GetAttributeSet()->OnStaminaChanged.AddDynamic(this, &UCPlayerWidget::OnStaminaChange);
	}

	if(AimImage)
		SetAimWidget(false);
}

void UCPlayerWidget::UpdateHealthBar(float Health)
{
	if (PlayerHealthBar)
	{
		PlayerHealthBar->SetPercent(Health / 100.f);  // 0 ~ 100 사이로 비율 계산
	}
}

void UCPlayerWidget::UpdateStaminaBar(float Stamina)
{
	if (PlayerStaminaBar)
	{
		PlayerStaminaBar->SetPercent(Stamina / 100.f);  // 0 ~ 100 사이로 비율 계산
	}
}

void UCPlayerWidget::UpdateEquipWeaponName(FText WeaponName)
{
	EquipWeaponName->SetText(WeaponName);
}

void UCPlayerWidget::UpdateEquipWeaponImage(UTexture* WeaponImage)
{
	EquipWeaponImage->Brush.SetResourceObject(WeaponImage);
}

void UCPlayerWidget::UpdateCurrentBullet(float Value)
{
	CurrentBullet->SetText(FText::AsNumber(Value));
}

void UCPlayerWidget::UpdateBaseBullet(float Value)
{
	BaseBullet->SetText(FText::AsNumber(Value));
}

void UCPlayerWidget::ShowCurrentBullet(bool state)
{
	if (state)
	{
		CurrentBullet->SetVisibility(ESlateVisibility::Visible);
		BaseBullet->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		CurrentBullet->SetVisibility(ESlateVisibility::Hidden);
		BaseBullet->SetVisibility(ESlateVisibility::Hidden);
	}

}

void UCPlayerWidget::SetAimWidget(bool state)
{
	if (state)
	{
		AimImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		AimImage->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UCPlayerWidget::OnHealthChange(float NewHealth)
{
	UpdateHealthBar(NewHealth);
}

void UCPlayerWidget::OnStaminaChange(float NewStamina)
{
	UpdateStaminaBar(NewStamina);
}
