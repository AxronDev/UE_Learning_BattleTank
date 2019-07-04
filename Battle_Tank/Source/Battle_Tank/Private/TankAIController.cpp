// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("AI cannot find player tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank %s"), *(PlayerTank->GetName()))
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank() != nullptr)
		if (GetControlledTank() != nullptr)
		{
			GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		}
}


ATank *ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank *ATankAIController::GetPlayerTank() const
{
	auto *PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn == nullptr) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
	
}