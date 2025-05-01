// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitideEnemyCharacter.h"
#include "InfinitidePlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

AInfinitideEnemyCharacter::AInfinitideEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	m_TrackingSpeed = 300.f;

	m_AttackRange = 100.f;
	m_AttackDamage = 10.0f;
	m_AttackCooldown = 1.5f;
	m_AttackTimer = 0.0f;

	m_ExpReward = 200.0f;
}

void AInfinitideEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_TargetPlayer = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AInfinitideEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_AttackTimer -= DeltaTime;
	MoveToPlayer(DeltaTime);

	if (m_TargetPlayer && m_AttackTimer <= 0.0f)
	{
		float Distance = FVector::Dist(GetActorLocation(), m_TargetPlayer->GetActorLocation());
		if (Distance <= m_AttackRange)
		{
			AInfinitideCharacter* TargetCharacter = Cast<AInfinitideCharacter>(m_TargetPlayer);
			if (TargetCharacter)
			{
				UGameplayStatics::ApplyDamage(TargetCharacter, m_AttackDamage, GetInstigatorController(), this, nullptr);
				m_AttackTimer = m_AttackCooldown;
			}
		}
	}
}

void AInfinitideEnemyCharacter::MoveToPlayer(float DeltaTime)
{
	if (m_TargetPlayer == nullptr) return;

	FVector Direction = (m_TargetPlayer->GetActorLocation() - GetActorLocation());
	AddMovementInput(Direction, 1.0f);
}

void AInfinitideEnemyCharacter::Die()
{

	if (m_DeathEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_DeathEffect, GetActorLocation(), GetActorRotation());
	}

	AInfinitidePlayerCharacter* Killer = Cast<AInfinitidePlayerCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (Killer)
	{
		Killer->AddExperience(m_ExpReward);
	}

	Super::Die();

}
