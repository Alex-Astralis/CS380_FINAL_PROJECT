// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BrainComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

void AMyAIController::BeginPlay()
{
  Super::BeginPlay();
  UE_LOG(LogBehaviorTree, Warning, TEXT("Begin C++ AI Controller"));
}

void AMyAIController::PushBehaviorTree(UBehaviorTree* newTree)
{
  if (m_CurrentTree == NULL || newTree == NULL)
  {
    UE_LOG(LogBehaviorTree, Error, TEXT("NULL Behavior Trees from blueprints"));
    return;
  }

  UE_LOG(LogBehaviorTree, Warning, TEXT("Push onto stack."));
  BrainComponent->PauseLogic("Cuz");
  m_StackBrainComponents.Push(BrainComponent);
  m_StackBT.Push(m_CurrentTree);
  ++m_Count;

  BrainComponent = nullptr;
  Blackboard = nullptr;
  RunBehaviorTree(newTree);
}

void AMyAIController::PopBehaviorTree()
{
  UE_LOG(LogBehaviorTree, Warning, TEXT("Pop from stack."));
  if(!m_Count)
    return;

  BrainComponent->Cleanup();

  UBehaviorTree* tree = m_StackBT.Pop(true);
  BrainComponent = m_StackBrainComponents.Pop(true);
  BrainComponent->ResumeLogic(TEXT("Cuz Ya"));
  --m_Count;

  if (tree == NULL)
  {
    UE_LOG(LogBehaviorTree, Error, TEXT("NULL Behavior Tree from stack"));
    return;
  }
  RunBehaviorTree(tree);
  /*UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(BrainComponent);
  if (BTComp == NULL || tree == NULL)
  {
    UE_LOG(LogBehaviorTree, Error, TEXT("NULL Behavior Trees from stack"));
    return;
  }
  BTComp->StartTree(*tree, EBTExecutionMode::Looped);*/
}

void AMyAIController::SetBehaviorTree(UPARAM(DisplayName = "Current Tree") UBehaviorTree* tree)
{
  if (tree)
  {
    m_CurrentTree = tree;
  }
  else
  {
    UE_LOG(LogBehaviorTree, Error, TEXT("NULL Behavior Tree set"));
    return;
  }
}