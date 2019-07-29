// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 50.0; // In degrees

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.0; // In degrees
};
