// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"

ATank *ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (ControlledTank == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("AI PlayerController not Possesing a tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI PlayerController controlling %s"), *(ControlledTank->GetName()))
}
