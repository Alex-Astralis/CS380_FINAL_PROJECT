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
  UFUNCTION(BlueprintCallable, Category = "Behavior Tree")
    void PushBehaviorTree(UPARAM(DisplayName = "Next Tree") UBehaviorTree* newTree);

  UFUNCTION(BlueprintCallable, Category = "Behavior Tree")
    void PopBehaviorTree();
  uint32 Count() { return m_Count; }

  UFUNCTION(BlueprintCallable, Category = "Behavior Tree")
    void SetBehaviorTree(UPARAM(DisplayName = "Current Tree") UBehaviorTree* tree);

private:
  TArray<UBehaviorTree*> m_StackBT;
  TArray<UBrainComponent*> m_StackBrainComponents;
  uint32 m_Count;

  UBehaviorTree* m_CurrentTree;
};