#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/JStateComponent.h"
#include "JCharacterData.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FMontageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EStateType Name;
	UPROPERTY(EditAnywhere)
	UAnimMontage* Montage;
	UPROPERTY(EditAnywhere)
	float PlayRate = 1.f;
	UPROPERTY(EditAnywhere)
	FName StartSection;
};

USTRUCT(BlueprintType)
struct FAttributeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float HealthPoint;
	UPROPERTY(EditAnywhere)
	float SteminaPoint;
};

/**
 * 
 * This is for Asset Management
 * Many Components will use this class
 * to find Assets they need
 * 
 */
UCLASS()
class RUNANDJUMP_API UJCharacterData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Montage")
	FMontageData RollMontage;
	UPROPERTY(EditAnywhere, Category = "Montage")
	FMontageData AttackMontage;
	UPROPERTY(EditAnywhere, Category = "Montage")
	FMontageData HittedMontage;
	UPROPERTY(EditAnywhere, Category = "Attribute")
	FAttributeData Attribute;
};
