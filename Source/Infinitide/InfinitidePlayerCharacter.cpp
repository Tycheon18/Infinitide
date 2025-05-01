// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitidePlayerCharacter.h"
#include "InfinitideProjectile.h"

AInfinitidePlayerCharacter::AInfinitidePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	m_Level = 1;
	m_CurrentExp = 0.0f;
	m_ExpToNextLevel = 100.0f;
	m_ExpGrowthRate = 1.25f;
}

void AInfinitidePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AInfinitidePlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AInfinitidePlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AInfinitidePlayerCharacter::Fire);
}

void AInfinitidePlayerCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AInfinitidePlayerCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AInfinitidePlayerCharacter::AddExperience(float ExpAmount)
{
	m_CurrentExp += ExpAmount;

	while (m_CurrentExp >= m_ExpToNextLevel)
	{
		m_CurrentExp -= m_ExpToNextLevel;
		LevelUp();
	}
}

void AInfinitidePlayerCharacter::LevelUp()
{
	m_Level++;
	m_ExpToNextLevel *= m_ExpGrowthRate;

	UE_LOG(LogTemp, Warning, TEXT("Level UP! Current Level : %d"), m_Level);
}

void AInfinitidePlayerCharacter::Fire()
{
	if (m_ProjectileClass)
	{
		FVector MuzzleLocation = GetActorLocation() + GetActorForwardVector() * 100.0f;
		FRotator MuzzleRotation = GetControlRotation();

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		GetWorld()->SpawnActor<AInfinitideProjectile>(m_ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	}
}
