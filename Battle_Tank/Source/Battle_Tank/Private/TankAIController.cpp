// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move toward Player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

	// Aim toward Player
	if (!ensure(AimingComponent)) { return; }
				AimingComponent->AimAt(PlayerTank->GetActorLocation());
	// If Aiming or Locked, Fire
	if (AimingComponent->GetFiringState() == EFiringStatus::Locked)
		AimingComponent->Fire();
}