// Copyright Euphoria Games LLT.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("Horse: Tank Constructor"))
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP Begin Play to work
	// ...

	UE_LOG(LogTemp, Warning, TEXT("Horse: Tank Begin Play"))
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	UE_LOG(LogTemp, Warning, TEXT("FIRE IN THE HOLE!!!!"))
		if (isReloaded)
		{

			// Spawn projectile at socket location on barrel
			auto Projectile = GetWorld()->SpawnActor<AProjectile>(
				ProjectileBluePrint,
				Barrel->GetSocketLocation(FName("ProjectilePos")),
				Barrel->GetSocketRotation(FName("ProjectilePos"))
				);
			Projectile->LaunchProjectile(LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
		}
}