#include "JWeapon.h"
#include "Global.h"
#include "GameFramework/Character.h"

AJWeapon::AJWeapon()
{
}

void AJWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AJWeapon::DoDamage);
}

void AJWeapon::DoDamage(AActor* OverlappedActor, AActor* OtherActor)
{
	CheckTrue(Cast<ACharacter>(OverlappedActor) == OwnerCharacter);

	FDamageEvent DamageEvent;
	OtherActor->TakeDamage(10.f, DamageEvent, OwnerCharacter->Controller, OverlappedActor);
}


