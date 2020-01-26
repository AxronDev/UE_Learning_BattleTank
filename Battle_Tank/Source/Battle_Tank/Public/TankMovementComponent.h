// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

private:
	UTankTrack *LeftTrack = nullptr;
	UTankTrack *RightTrack = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

};
