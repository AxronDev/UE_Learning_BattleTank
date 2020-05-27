// Copyright Euphoria Games LLT.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * Responsible for helping the palyer aim.
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent *AimCompRef);

private:
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector &OutHitLocation, FVector LookDirection) const;

	virtual void SetPawn(APawn * InPawn) override;


	UFUNCTION()
	void OnPossessedTankDeath();

	UPROPERTY(EditAnywhere)
	float CrossHairXScale {0.5};

	UPROPERTY(EditAnywhere)
	float CrossHairYScale{0.33333};

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};