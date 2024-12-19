#include "CEquipment.h"
#include "Global.h"
#include "Player/CPlayer.h"
#include "Weapon/CWeapon.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"

ACEquipment::ACEquipment()
{
	PrimaryActorTick.bCanEverTick = true;


}

void ACEquipment::BeginPlay()
{
	Super::BeginPlay();

	CheckNull(DataAsset);

	OwnerCharacter = Cast<ACPlayer>(GetOwner());
	CheckNull(OwnerCharacter);

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = OwnerCharacter;

	// 스폰시키고 숨기고 필요할때만 보여주는 방식.
	if (DataAsset->Datas[0].WeaponClass)
	{
		EquipWeapon[0] = OwnerCharacter->GetWorld()->SpawnActor<ACWeapon>(DataAsset->Datas[0].WeaponClass, SpawnParams);
		CheckNull(EquipWeapon[0]);

		EquipWeapon[0]->SetActorHiddenInGame(true);
	}

	if (DataAsset->Datas[1].WeaponClass)
	{
		EquipWeapon[1] = OwnerCharacter->GetWorld()->SpawnActor<ACWeapon>(DataAsset->Datas[1].WeaponClass, SpawnParams);
		CheckNull(EquipWeapon[1]);

		EquipWeapon[1]->SetActorHiddenInGame(true);
	}

	if (DataAsset->Datas[2].WeaponClass)
	{
		EquipWeapon[2] = OwnerCharacter->GetWorld()->SpawnActor<ACWeapon>(DataAsset->Datas[2].WeaponClass, SpawnParams);
		CheckNull(EquipWeapon[2]);

		EquipWeapon[2]->SetActorHiddenInGame(true);
	}

	if (DataAsset->Datas[3].WeaponClass)
	{
		EquipWeapon[3] = OwnerCharacter->GetWorld()->SpawnActor<ACWeapon>(DataAsset->Datas[3].WeaponClass, SpawnParams);
		CheckNull(EquipWeapon[3]);

		EquipWeapon[3]->SetActorHiddenInGame(true);
	}

}

void ACEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACEquipment::Equip(int32 slot)
{
	CheckNull(EquipMontage);

	OwnerCharacter->PlayAnimMontage(EquipMontage);

	NewWeapon = EquipWeapon[slot - 1];

	// 위젯 변화
}

void ACEquipment::Begin_Equip()
{
	// 무기 손 소켓에 붙이기
	CheckNull(NewWeapon);

	if (CurrentEquipWeapon)
	{
		CurrentEquipWeapon->SetActorHiddenInGame(true);
		CurrentEquipWeapon->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		OwnerCharacter->GetTagContainer().RemoveTag(*(CurrentEquipWeapon->GetTag()));

		if (CurrentEquipWeapon == NewWeapon)
		{
			CurrentEquipWeapon = nullptr;
			return;
		}

		CurrentEquipWeapon = nullptr;

	}

	NewWeapon->SetActorHiddenInGame(false); 
	NewWeapon->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, NewWeapon->GetSocketName());

	OwnerCharacter->GetTagContainer().AddTag(*(NewWeapon->GetTag()));

	CurrentEquipWeapon = NewWeapon;
}

void ACEquipment::MainAction()
{
	CheckNull(CurrentEquipWeapon);

	CurrentEquipWeapon->GetAbilitySystemComponent()->TryActivateAbility(CurrentEquipWeapon->GetWeaponAbilitySpec().Handle);

	// 스테미너 감소
}

