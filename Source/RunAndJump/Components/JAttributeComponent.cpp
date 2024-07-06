#include "JAttributeComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

UJAttributeComponent::UJAttributeComponent()
{
	UDataAsset* DataAsset;
	CHelpers::GetAsset<UDataAsset>(&DataAsset, "/Game/DataAsset/DA_Character");
	
	// Set OwnerCharacter
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	CheckNull(OwnerCharacter);

	// Set Attribute
	UJCharacterData* CharacterDataAsset = Cast<UJCharacterData>(DataAsset);
	CheckNull(CharacterDataAsset);

	//->HealthPoint
	HealthPoint = CharacterDataAsset->Attribute.HealthPoint;

	//->SteminaPoint
	SteminaPoint = CharacterDataAsset->Attribute.SteminaPoint;
}


void UJAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

}


