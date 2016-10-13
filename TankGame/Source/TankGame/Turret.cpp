// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Turret.h"

void UTurret::RotateTurret(float Direction) {

	Direction = FMath::Clamp<float>(Direction, -1, 1);
	auto TurretMoveByRotation = Direction*RotationPerSecond*GetWorld()->DeltaTimeSeconds;
	auto NewTurretRotation = RelativeRotation.Yaw + TurretMoveByRotation;

	SetRelativeRotation(FRotator(0,NewTurretRotation,0));
}

