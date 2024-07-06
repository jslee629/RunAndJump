#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/JStateComponent.h"
#include "JPlayer.generated.h"

class UMaterialInstanceDynamic;
class UJAttributeComponent;
class UJStateComponent;
class UJMontageComponent;
class AJWeapon;

UCLASS()
class RUNANDJUMP_API AJPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AJPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Axis Func
	void OnMoveForward(float AxisValue);

	// Action Func
	void OnJump();
	void OnRoll();

	UFUNCTION(BlueprintNativeEvent)
	void OnAttack();

public:
	UFUNCTION()
	void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

private:
	UMaterialInstanceDynamic* BodyMaterial;
	UMaterialInstanceDynamic* LogoMaterial;
	AJWeapon* Weapon;
	UEnum* StateTypeAsUEnum;

public:
	// Components
	UPROPERTY(BlueprintReadOnly, Instanced, VisibleDefaultsOnly, Category = "Components")
	UJAttributeComponent* AttributeComp;
	UPROPERTY(BlueprintReadOnly, Instanced, VisibleDefaultsOnly, Category = "Components")
	UJStateComponent* StateComp;
	UPROPERTY(BlueprintReadOnly, Instanced, VisibleDefaultsOnly, Category = "Components")
	UJMontageComponent* MontagesComp;
};
