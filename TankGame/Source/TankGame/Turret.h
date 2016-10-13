// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void RotateTurret(float Direction);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float RotationPerSecond = 25;

	
	
};
