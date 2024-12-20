#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPlayerWidget.generated.h"

class UProgressBar;
class UEditableTextBox;
class UImage;

UCLASS()
class PORTFOLIO_API UCPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnHealthChange(float NewHealth);

	UFUNCTION()
		void OnStaminaChange(float NewStamina);
	
	void UpdateHealthBar(float Health);
	void UpdateStaminaBar(float Stamina);

	void UpdateEquipWeaponName(FText WeaponName);
	void UpdateEquipWeaponImage(UImage* WeaponImage);

public:
	UPROPERTY(meta = (BindWidget))
		UProgressBar* PlayerHealthBar;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* PlayerStaminaBar;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* PetHealthBar;

	UPROPERTY(meta = (BindWidget))
		UEditableTextBox* EquipWeaponName;

	UPROPERTY(meta = (BindWidget))
		UImage* EquipWeaponImage;
};
