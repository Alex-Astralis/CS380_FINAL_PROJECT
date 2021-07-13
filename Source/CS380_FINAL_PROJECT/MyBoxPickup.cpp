// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoxPickup.h"

// Set default value
AMyBoxPickup::AMyBoxPickup()
{
  GetMesh()->SetSimulatePhysics(true);
}

void AMyBoxPickup::WasCollected_Implementation()
{
  // Use base pickup behavior
  Super::WasCollected_Implementation();

  // Destroy the Battery
  Destroy();
}