// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitideProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "InfinitideCharacter.h"

// Sets default values
AInfinitideProjectile::AInfinitideProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	m_CollisionComponent->SetSphereRadius(10.0f);
	m_CollisionComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = m_CollisionComponent;

	m_MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	m_MovementComponent->UpdatedComponent = m_CollisionComponent;
	m_MovementComponent->InitialSpeed = 1000.f;
	m_MovementComponent->MaxSpeed = 1000.f;
	m_MovementComponent->bRotationFollowsVelocity = true;

	m_Damage = 25.0f;

	m_CollisionComponent->OnComponentHit.AddDynamic(this, &AInfinitideProjectile::OnHit);

}

// Called when the game starts or when spawned
void AInfinitideProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInfinitideProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInfinitideProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NomalImpulse, const FHitResult& Hit)
{
	HitCharacter = Cast<AInfinitideCharacter>(OtherActor);

	if (HitCharacter)
	{
		UGameplayStatics::ApplyDamage(HitCharacter, m_Damage, GetInstigatorController(), this, nullptr);
	}

	Destroy();
}

