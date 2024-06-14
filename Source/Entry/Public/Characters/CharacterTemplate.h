#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTemplate.generated.h"

UCLASS()
class ENTRY_API ACharacterTemplate : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterTemplate();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveSides(float Value);
	void Turn(float Value);
	void LookUp(float Value);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere) class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere) class UCameraComponent* ViewCamera;
	UPROPERTY(VisibleAnywhere, Category = Hair) class UGroomComponent* Hair;
	UPROPERTY(VisibleAnywhere, Category = Hair) class UGroomComponent* Eyebrows;
};