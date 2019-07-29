// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; // Relative Speed is the percent of the max speed
	auto Elevation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Elevation, 0));
}