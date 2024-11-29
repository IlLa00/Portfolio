#include "CMonster.h"
#include "Global.h"
#include "DataAsset/CMonsterMeshDataAsset.h"
#include "GameFramework/CharacterMovementComponent.h"

ACMonster::ACMonster()
{
	GetCharacterMovement()->MaxWalkSpeed = 200.f; // 이거 수정해야할지도?
}

void ACMonster::BeginPlay()
{
	Super::BeginPlay();

	if (this->GetMesh()->GetSkeletalMeshAsset() == DataAsset->Datas[0].SkeletalMeshAssets)
	{
		GetMesh()->SetAnimClass(DataAsset->Datas[0].AnimClass);
	}
	else if (this->GetMesh()->GetSkeletalMeshAsset() == DataAsset->Datas[1].SkeletalMeshAssets)
	{
		GetMesh()->SetAnimClass(DataAsset->Datas[1].AnimClass);
	}

	
}

void ACMonster::SetMesh(FName PlayerArea) // 여기문제 없음
{
	if (DataAsset && PlayerArea == "Grasslands")
	{
		if (FMath::FRand() < 0.5f) 
		{
			GetMesh()->SetSkeletalMesh(DataAsset->Datas[0].SkeletalMeshAssets);
			GetMesh()->SetRelativeLocation(FVector(0, 0, -80));
			GetMesh()->SetRelativeRotation(FRotator(0, 90, 0));
		}
		else
		{
			GetMesh()->SetSkeletalMesh(DataAsset->Datas[1].SkeletalMeshAssets);
			GetMesh()->SetRelativeLocation(FVector(0, 0, -80));
			GetMesh()->SetRelativeRotation(FRotator(0, 90, 0));
		}
	}
}
