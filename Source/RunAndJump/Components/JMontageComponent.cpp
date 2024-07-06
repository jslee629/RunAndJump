#include "JMontageComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Player/JPlayer.h"

UJMontageComponent::UJMontageComponent()
{
	UDataAsset* DataAsset;
	CHelpers::GetAsset<UDataAsset>(&DataAsset, "/Game/DataAsset/DA_Character");

	// Set OwnerCharacter
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	CheckNull(OwnerCharacter);

	// Set Montages
	UJCharacterData* CharacterDataAsset = Cast<UJCharacterData>(DataAsset);
	CheckNull(CharacterDataAsset);

	//->Roll
	CharacterDataAsset->RollMontage.Name == EStateType::Roll ? RollMontage = CharacterDataAsset->RollMontage : CLog::Log("RollMontage Asset error : Check DataAsset");

	//->Attack
	CharacterDataAsset->AttackMontage.Name == EStateType::Attack ? AttackMontage = CharacterDataAsset->AttackMontage : CLog::Log("AttackMontage Asset error : Check DataAsset");

	//->Hitted
	CharacterDataAsset->HittedMontage.Name == EStateType::Hitted ? HittedMontage = CharacterDataAsset->HittedMontage : CLog::Log("HittedMontage Asset error : Check DataAsset");
}


void UJMontageComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UJMontageComponent::PlayRoll()
{
	AJPlayer* Player = Cast<AJPlayer>(OwnerCharacter);
	CheckNull(Player);

	Player->PlayAnimMontage(RollMontage.Montage, RollMontage.PlayRate, RollMontage.StartSection);
}

void UJMontageComponent::PlayAttack()
{
	AJPlayer* Player = Cast<AJPlayer>(OwnerCharacter);
	CheckNull(Player);

	Player->PlayAnimMontage(AttackMontage.Montage, AttackMontage.PlayRate, AttackMontage.StartSection);
}

void UJMontageComponent::PlayHitted()
{
	AJPlayer* Player = Cast<AJPlayer>(OwnerCharacter);
	CheckNull(Player);

	Player->PlayAnimMontage(HittedMontage.Montage, HittedMontage.PlayRate, HittedMontage.StartSection);
}



