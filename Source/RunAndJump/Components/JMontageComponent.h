#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JCharacterData.h"
#include "JMontageComponent.generated.h"

class FMontageStruct;
class ACharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNANDJUMP_API UJMontageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UJMontageComponent();

protected:
	virtual void BeginPlay() override;

public:
	void PlayRoll();
	void PlayAttack();
	void PlayHitted();

private:
	FMontageData RollMontage;
	FMontageData AttackMontage;
	FMontageData HittedMontage;

public:
	ACharacter* OwnerCharacter;
};
