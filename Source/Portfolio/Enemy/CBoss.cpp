#include "Enemy/CBoss.h"
#include "Global.h"

ACBoss::ACBoss()
{
	USkeletalMesh* MeshAsset;
	CHelpers::GetAsset(&MeshAsset, "/Game/Assets/FourEvilDragonsHP/Meshes/DragonTheUsurper/DragonTheUsurperSK");
	CheckNull(MeshAsset);

	CHelpers::GetClass(&AnimClass, "/Game/Enemy/Boss/ABP_CBoss");
	CheckNull(AnimClass);

	GetMesh()->SetSkeletalMesh(MeshAsset);
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	
}

void ACBoss::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->SetAnimClass(AnimClass);
}
