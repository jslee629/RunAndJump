#include "JAnimNotify_EndAttack.h"
#include "Global.h"
#include "Player/JPlayer.h"

FString UJAnimNotify_EndAttack::GetNotifyName_Implementation() const
{
	return "EndAttack";
}

void UJAnimNotify_EndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp);

	AJPlayer* Player = Cast<AJPlayer>(MeshComp->GetOwner());
	CheckNull(Player);

	Player->StateComp->SetTypeIdle();
}
