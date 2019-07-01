// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetControlledTank();
	if (PlayerTank == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("Cannot find player tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("Player possesing tank %s"), *(PlayerTank->GetName()))
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetControlledTank() == nullptr) { return; }

	FVector HitLocation; // OUT Parameter
	GetSightRayHitLocation(HitLocation);
	// Get world location of linetrace through crosshair
	// If it hits landscape
		// Tell controlled tank to aim at this point
}


bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(
		ViewportSizeX * CrossHairXScale, 
		ViewportSizeY * CrossHairYScale);
	// Deproject the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString())
	}
	// Line-trace along that look direction and see what we hit (up to max range)
	OutHitLocation = FVector(1.0);
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, 
		ScreenLocation.Y, 
		WorldLocation, 
		LookDirection);
}


ATank *ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}