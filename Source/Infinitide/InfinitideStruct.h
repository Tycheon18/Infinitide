// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InfinitideStruct.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FInfinitideUpgradeOption
{
	GENERATED_BODY()

public:
	FInfinitideUpgradeOption();
	~FInfinitideUpgradeOption();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 UpgradeId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Value;
};

UCLASS()
class INFINITIDE_API AInfinitideStruct : public AActor
{
    GENERATED_BODY()

public:
	AInfinitideStruct();

};
