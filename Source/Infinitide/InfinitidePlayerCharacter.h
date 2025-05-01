// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfinitideCharacter.h"
#include "InfinitidePlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class INFINITIDE_API AInfinitidePlayerCharacter : public AInfinitideCharacter
{
	GENERATED_BODY()
	
public:

	AInfinitidePlayerCharacter();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Level")
	int32 m_Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Level")
	float m_CurrentExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Level")
	float m_ExpToNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Level")
	float m_ExpGrowthRate;

public:
	UFUNCTION(BlueprintCallable, Category = "Stats|Level")
	void AddExperience(float ExpAmount);

protected:
	UFUNCTION(BlueprintCallable, Category = "Stats|Level")
	void LevelUp();

protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<class AInfinitideProjectile> m_ProjectileClass;

	UFUNCTION(BlueprintCallable)
	void Fire();


};
