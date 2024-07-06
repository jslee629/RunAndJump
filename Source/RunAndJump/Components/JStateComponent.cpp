#include "JStateComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

UJStateComponent::UJStateComponent()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	CheckNull(OwnerCharacter);
}

void UJStateComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UJStateComponent::SetTypeIdle()
{
	ChangeType(EStateType::Idle);
}

void UJStateComponent::SetTypeRoll()
{
	ChangeType(EStateType::Roll);
}

void UJStateComponent::SetTypeJump()
{
	ChangeType(EStateType::Jump);
}

void UJStateComponent::SetTypeAttack()
{
	ChangeType(EStateType::Attack);
}

void UJStateComponent::SetTypeHitted()
{
	ChangeType(EStateType::Hitted);
}

void UJStateComponent::SetTypeDead()
{
	ChangeType(EStateType::Dead);
}

void UJStateComponent::ChangeType(EStateType InNewType)
{
	if (OnStateTypeChanged.IsBound())
	{
		EStateType Prev = Type;
		Type = InNewType;

		OnStateTypeChanged.Broadcast(Prev, InNewType);
	}
}



