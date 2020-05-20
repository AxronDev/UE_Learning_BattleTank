// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BluePrintSpawnableComponent))
class BATTLE_TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

	UTankTrack();

	void ApplySidewaysForce();

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;

public:
	void DriveTrack();
	// Sets throttle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000;
	// Assume 40 kg, 1g acceleration
};
