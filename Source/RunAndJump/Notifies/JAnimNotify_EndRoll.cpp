#include "JAnimNotify_EndRoll.h"
#include "Global.h"
#include "Player/JPlayer.h"

FString UJAnimNotify_EndRoll::GetNotifyName_Implementation() const
{
	return "EndRoll";
}

void UJAnimNotify_EndRoll::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp);

	AJPlayer* Player = Cast<AJPlayer>(MeshComp->GetOwner());
	CheckNull(Player);

	Player->StateComp->SetTypeIdle();
}
