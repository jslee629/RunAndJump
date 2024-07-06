#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JCharacterData.h"
#include "JAttributeComponent.generated.h"

class ACharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNANDJUMP_API UJAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UJAttributeComponent();

protected:
	virtual void BeginPlay() override;

private:
	float HealthPoint;
	float SteminaPoint;

public:
	ACharacter* OwnerCharacter;
};
