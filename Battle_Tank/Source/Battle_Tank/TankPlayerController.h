// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank *GetControlledTank() const;

private:
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector &OutHitLocation, FVector LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXScale {0.5};

	UPROPERTY(EditAnywhere)
	float CrossHairYScale{0.33333};

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};