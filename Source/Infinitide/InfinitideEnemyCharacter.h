// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfinitideCharacter.h"
#include "InfinitideEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class INFINITIDE_API AInfinitideEnemyCharacter : public AInfinitideCharacter
{
	GENERATED_BODY()
	
public:
	
	AInfinitideEnemyCharacter();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

protected:
	
	AActor* m_TargetPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float m_TrackingSpeed;

	void MoveToPlayer(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Enemy|Attack")
	float m_AttackRange;

	UPROPERTY(EditAnywhere, Category = "Enemy|Attack")
	float m_AttackDamage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Attack")
	float m_AttackCooldown;

	float m_AttackTimer;

	UPROPERTY(EditAnywhere, Category = "Effect")
	class UNiagaraSystem* m_DeathEffect;


	virtual void Die() override;
};
 