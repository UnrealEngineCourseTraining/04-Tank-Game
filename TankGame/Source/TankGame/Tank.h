// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Declarations
class UTankBarrel; 
class UTurret;
class UTankAimingComponent;

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BluePrintCallable, Category =Setup)
	void SetBarrelReference(UTankBarrel* BarelToSet);
	UFUNCTION(BluePrintCallable, Category = Setup)
	void SetTurretReference(UTurret* Turret);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;// TODO sensible value
	
};
