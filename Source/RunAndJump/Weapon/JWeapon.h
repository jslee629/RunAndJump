#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JWeapon.generated.h"

class ACharacter;

UCLASS()
class RUNANDJUMP_API AJWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AJWeapon();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void DoDamage(AActor* OverlappedActor, AActor* OtherActor);

private:
	ACharacter* OwnerCharacter;

};
