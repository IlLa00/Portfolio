#include "CEquipment.h"
#include "Global.h"
#include "Player/CPlayer.h"
#include "Weapon/CWeapon.h"

ACEquipment::ACEquipment()
{
	PrimaryActorTick.bCanEverTick = true;

	
}

void ACEquipment::BeginPlay()
{
	Super::BeginPlay();

	CheckNull(DataAsset);
	
	/*EquipWeapon[0] = Cast<ACWeapon>(DataAsset->Datas[0].WeaponClass);
	CheckNull(EquipWeapon[0]);*/

	OwnerCharacter = Cast<ACPlayer>(GetOwner());
	CheckNull(OwnerCharacter);

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = OwnerCharacter;

	// ������Ű�� ����� �ʿ��Ҷ��� �����ִ� ���.
	EquipWeapon[0] = OwnerCharacter->GetWorld()->SpawnActor<ACWeapon>(DataAsset->Datas[0].WeaponClass, SpawnParams);
	CheckNull(EquipWeapon[0]); 

	EquipWeapon[0]->SetActorHiddenInGame(true);


}

void ACEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACEquipment::Equip(int32 slot)
{
	CheckNull(EquipMontage);

	OwnerCharacter->PlayAnimMontage(EquipMontage);
	
	// ���� ��ȭ
	// ���� ���������� �ƴ���?
}

void ACEquipment::Begin_Equip()
{
	// ���� �� ���Ͽ� ���̱�
	EquipWeapon[0]->SetActorHiddenInGame(false);

	EquipWeapon[0]->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "hand_r");

	// EquipWeapon[0]->GetD
	// �ɷ� ����
}

void ACEquipment::MainAction()
{
	// TryAbility~
}
