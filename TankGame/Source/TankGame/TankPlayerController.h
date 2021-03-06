// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would be hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation=0.5,CrossHairYLocation=0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 10000000.f;

	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& Hit) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
};
