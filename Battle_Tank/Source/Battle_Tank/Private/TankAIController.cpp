// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (!ensure(PlayerTank))
		if (ensure(ControlledTank))
		{
			// Move toward Player
			MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

			// Aim toward Player
			ControlledTank->AimAt(PlayerTank->GetActorLocation());

			// Fire!
			ControlledTank->Fire();
		}
}