// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not Possesing a tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("PlayerController controlling %s"), *(ControlledTank->GetName()))
}

ATank *ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}