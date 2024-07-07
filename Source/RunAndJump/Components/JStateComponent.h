#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JStateComponent.generated.h"

UENUM(BlueprintType)
enum class EStateType : uint8
{
	Idle,
	Roll,
	Jump,
	Attack,
	Hitted,
	Dead,
	Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateTypeChanged, EStateType, InPrevType, EStateType, InNewType);

/**
 * This is for Character State Management
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNANDJUMP_API UJStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UJStateComponent();

protected:
	virtual void BeginPlay() override;

public:
	// State Getter
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE EStateType GetType() { return Type; }

	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsIdle() { return Type == EStateType::Idle; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsRoll() { return Type == EStateType::Roll; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsJump() { return Type == EStateType::Jump; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsAttack() { return Type == EStateType::Attack; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsHitted() { return Type == EStateType::Hitted; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsDead() { return Type == EStateType::Dead; }
		
	// State Setter
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetTypeIdle();
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetTypeRoll();
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetTypeJump();
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetTypeAttack();
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetTypeHitted();
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetTypeDead();

private:
	void ChangeType(EStateType InNewType);

public:
	UPROPERTY(BlueprintAssignable)
	FStateTypeChanged OnStateTypeChanged;

private:
	EStateType Type;

public:
	ACharacter* OwnerCharacter;
};
