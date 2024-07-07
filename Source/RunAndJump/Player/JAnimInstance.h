#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Components/JStateComponent.h"
#include "JAnimInstance.generated.h"

class ACharacter;

UCLASS()
class RUNANDJUMP_API UJAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "BlendSpace")
	float Speed;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "BlendSpace")
	float Direction;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "State")
	EStateType StateType;
};
