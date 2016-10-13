// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI possessing: %s"), *(ControlledTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		//TODO Move towards the player

		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto TankPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!TankPlayer) { return nullptr; }
	return Cast<ATank>(TankPlayer);
}



