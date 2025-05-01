// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitideCharacter.h"

// Sets default values
AInfinitideCharacter::AInfinitideCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_MaxHealth = 100.f;
	m_CurrentHealth = m_MaxHealth;
	m_MoveSpeed = 600.f;

}

// Called when the game starts or when spawned
void AInfinitideCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInfinitideCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInfinitideCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AInfinitideCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (DamageAmount <= 0.0f || m_CurrentHealth <= 0.0f) return 0.0f;

	m_CurrentHealth -= DamageAmount;
	m_CurrentHealth = FMath::Max(0.0f, m_CurrentHealth);

	if (m_CurrentHealth <= 0.0f)
	{
		Die();
	}
	
	return DamageAmount;
}

void AInfinitideCharacter::Die()
{
	Destroy();
}

