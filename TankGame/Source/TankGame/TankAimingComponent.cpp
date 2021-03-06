// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankBarrel.h"
#include "Turret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTurret* TurretToSet) {
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution=UGameplayStatics::SuggestProjectileVelocity
		(this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
			false,
			0,
			0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);

	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No Aim solution"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	//Work-out difference between current barrel rotation and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//Turret difference
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto TurretDeltaRotator = AimAsRotator - TurretRotator;

	UE_LOG(LogTemp, Warning, TEXT("AimsAsRotator: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch); //TODO remove magic number
	Turret->RotateTurret(TurretDeltaRotator.Yaw);
}

