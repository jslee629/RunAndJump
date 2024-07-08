#include "JPlayer.h"
#include "Global.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/JAttributeComponent.h"
#include "Components/JMontageComponent.h"
#include "Weapon/JWeapon.h"

AJPlayer::AJPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set Skeletal Mesh
	USkeletalMesh* MeshAsset;
	CHelpers::GetAsset(&MeshAsset, "/Game/Character/Mesh/SK_Mannequin");
	GetMesh()->SetSkeletalMesh(MeshAsset);
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88.f));

	TSubclassOf<UAnimInstance> AnimInstanceClass;
	CHelpers::GetClass<UAnimInstance>(&AnimInstanceClass, "/Game/Character/ABP_JPlayer");
	GetMesh()->SetAnimInstanceClass(AnimInstanceClass);

	// Set Character Movement
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->RotationRate = FRotator(0, 3600.f, 0);

	// Create Actor Component
	CHelpers::CreateActorComponent(this, &AttributeComp, "Attribute");
	CHelpers::CreateActorComponent(this, &StateComp, "State");
	CHelpers::CreateActorComponent(this, &MontagesComp, "Montages");
}

void AJPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Create Dynamic Material
	UMaterialInstanceConstant* BodyMaterialAsset;
	UMaterialInstanceConstant* LogoMaterialAsset;

	CHelpers::GetAssetDynamic(&BodyMaterialAsset, "/Game/Character/Materials/MI_UE4Man_Body_Inst");
	CHelpers::GetAssetDynamic(&LogoMaterialAsset, "/Game/Character/Materials/M_UE4Man_ChestLogo");

	BodyMaterial = UMaterialInstanceDynamic::Create(BodyMaterialAsset, this);
	LogoMaterial = UMaterialInstanceDynamic::Create(LogoMaterialAsset, this);

	GetMesh()->SetMaterial(0, BodyMaterial);
	GetMesh()->SetMaterial(1, LogoMaterial);

	// Bind
	StateComp->OnStateTypeChanged.AddDynamic(this, &AJPlayer::OnStateTypeChanged);
	StateTypeAsUEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EStateType"));

	// Spawn Waeapon And Attach
	AttachWeapon();
}

void AJPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AJPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind Axis Event
	PlayerInputComponent->BindAxis("MoveForward", this, &AJPlayer::OnMoveForward);

	// Bind Action Event
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AJPlayer::OnJump);
	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &AJPlayer::OnRoll);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AJPlayer::OnAttack);
}

void AJPlayer::OnMoveForward(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw * 100.f, 0);
	FVector Direction = FQuat(ControlRotation).GetForwardVector();

	AddMovementInput(Direction, AxisValue);
}

void AJPlayer::OnJump()
{
	Jump();
}

void AJPlayer::OnRoll()
{
	CheckTrue(StateComp->IsRoll());
	CheckTrue(StateComp->IsAttack());

	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	SetActorRotation(ControlRotation);

	StateComp->SetTypeRoll();
	MontagesComp->PlayRoll();
}

void AJPlayer::OnAttack_Implementation()
{
	CheckTrue(StateComp->IsAttack());
	CheckTrue(StateComp->IsRoll());

	StateComp->SetTypeAttack();
	MontagesComp->PlayAttack();
}

void AJPlayer::BeforeDead_Implementation()
{
	// Ragdoll
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->AddImpulse(FVector(0, 0, 1000.f));

	// Destroy
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AJPlayer::AfterDead, 5.f, false);
}

void AJPlayer::AfterDead_Implementation()
{
	//Destroy();
}

void AJPlayer::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{
	//FString StateTypeString = StateTypeAsUEnum->GetNameStringByValue((int64)InNewType);

	//CLog::Print(StateTypeString, 0, 10.f, FColor::Red);

	if (InNewType == EStateType::Dead)
	{
		BeforeDead();
	}
}

