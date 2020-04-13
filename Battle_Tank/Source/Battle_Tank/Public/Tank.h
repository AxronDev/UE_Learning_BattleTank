// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;
class UTankBarrel;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

		friend class ATankAIController;

private:
	// Sets default values for this pawn's properties
	ATank();
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;


	UFUNCTION(BlueprintCallable)
	void Fire();

	UTankBarrel *Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0.0;

protected:
	virtual void BeginPlay() override;


public:

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 7500; // TODO Find sensible starting value
};