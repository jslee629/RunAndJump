#include "JAnimInstance.h"
#include "Global.h"
#include "GameFramework/Character.h"

void UJAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	CheckNull(TryGetPawnOwner());
}

void UJAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* Character = Cast<ACharacter>(TryGetPawnOwner());
	CheckNull(Character);

	Speed = Character->GetVelocity().Size2D();
	Direction = CalculateDirection(Character->GetVelocity(), Character->GetControlRotation());
}