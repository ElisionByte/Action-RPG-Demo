#include "Characters/CharacterTemplate.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GroomComponent.h"

ACharacterTemplate::ACharacterTemplate()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->SetupAttachment(GetRootComponent());

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);

	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = FString("Head");

	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(GetMesh());
	Eyebrows->AttachmentName = FString("Head");
}

void ACharacterTemplate::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterTemplate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterTemplate::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ACharacterTemplate::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveSides"), this, &ACharacterTemplate::MoveSides);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ACharacterTemplate::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ACharacterTemplate::LookUp);
}

void ACharacterTemplate::MoveForward(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);
	}
}

void ACharacterTemplate::MoveSides(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		AddMovementInput(Direction, Value);
	}
}

void ACharacterTemplate::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ACharacterTemplate::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}