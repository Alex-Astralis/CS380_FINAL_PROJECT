// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BrainComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

void AMyAIController::BeginPlay()
{
  Super::BeginPlay();
  UE_LOG(LogBehaviorTree, Warning, TEXT("Begin C++ AI Controller"));
  m_CurrentTree = MoveBoxes;
}

void AMyAIController::Push(UBehaviorTree* newTree)
{
  UE_LOG(LogBehaviorTree, Warning, TEXT("Push onto stack."));
  BrainComponent->PauseLogic("Cuz");
  m_StackBrainComponents.Push(BrainComponent);
  m_StackBT.Push(m_CurrentTree);
  ++m_Count;

  BrainComponent = nullptr;
  Blackboard = nullptr;
  RunBehaviorTree(newTree);
}

void AMyAIController::Pop()
{
  UE_LOG(LogBehaviorTree, Warning, TEXT("Pop from stack."));
  if(!m_Count)
    return;

  BrainComponent->Cleanup();

  UBehaviorTree* tree = m_StackBT.Pop(true);
  BrainComponent = m_StackBrainComponents.Pop(true);
  BrainComponent->ResumeLogic(TEXT("Cuz Ya"));
  --m_Count;
}
