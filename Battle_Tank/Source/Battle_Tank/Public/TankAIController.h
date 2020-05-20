// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY (EditAnywhere, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptanceRadius = 3000; // How close AI should get to Player

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
