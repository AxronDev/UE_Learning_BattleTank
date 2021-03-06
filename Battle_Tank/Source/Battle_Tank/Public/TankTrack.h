// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 * Tank Track is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BluePrintSpawnableComponent))
class BATTLE_TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UTankTrack();

	TArray<ASprungWheel*> GetWheels() const;


public:
	void DriveTrack(float CurrentThrottle);
	// Sets throttle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000;
	// Assume 40 kg, 1g acceleration
};
