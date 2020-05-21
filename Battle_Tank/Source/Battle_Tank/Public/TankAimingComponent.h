// Copyright Euphoria Games LLT.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Empty,
	Reloading, 
	Aiming, 
	Locked
};

//Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	

	// Sets default values for this component's properties
	UTankAimingComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	bool IsBarrelMoving();

	FVector AimDirection{ NULL };
	double LastFireTime = 0.0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 Ammo = 3;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

	UFUNCTION(BlueprintCallable)
	int32 GetAmmo() const;

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);

	void AimAt(FVector HitLocation);

	void MoveBarrel(FVector AimDirection);
	
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 7500; // TODO Find sensible starting value

	UFUNCTION(BlueprintCallable)
	void Fire();

	EFiringStatus GetFiringState() const;


};
