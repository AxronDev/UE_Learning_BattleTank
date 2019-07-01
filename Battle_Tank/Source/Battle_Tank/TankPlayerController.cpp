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

}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetControlledTank() == nullptr) { return; }
	// Get world location of linetrace through crosshair
	// If it hits landscape
		// Tell controlled tank to aim at this point
}


ATank *ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}