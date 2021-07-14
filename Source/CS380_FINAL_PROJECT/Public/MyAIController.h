// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 *
 */

UCLASS()
class CS380_FINAL_PROJECT_API AMyAIController : public AAIController
{
  GENERATED_BODY()

public:

  void BeginPlay() override;
  void Push(UBehaviorTree* newTree);
  void Pop();
  uint32 Count() { return m_Count; }

  UPROPERTY(EditAnywhere)
    UBehaviorTree* MoveBoxes;

private:
  TArray<UBehaviorTree*> m_StackBT;
  TArray<UBrainComponent*> m_StackBrainComponents;
  uint32 m_Count;

  UBehaviorTree* m_CurrentTree;
};