// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MyBox.h"
#include "MyBoxPickup.generated.h"

/**
 * 
 */
UCLASS()
class CS380_FINAL_PROJECT_API AMyBoxPickup : public AMyBox
{
	GENERATED_BODY()


public:

  // Set default value for this actor's properties
  AMyBoxPickup();
	
  // Override WasCollected function - use Implementation because it's a Blueprint Native Event
  void WasCollected_Implementation() override;
};
