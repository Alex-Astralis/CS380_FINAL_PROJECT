// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBox.h"

// Sets default values
AMyBox::AMyBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// All Boxes start active
	bIsActive = true;

	// Create static Mesh Component
	MyBoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyBoxMesh"));
	RootComponent = MyBoxMesh;

}

// Called when the game starts or when spawned
void AMyBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Returns active state
bool AMyBox::IsActive()
{
	return bIsActive;
}

// Changes active state
void AMyBox::SetActive(bool NewBoxState)
{
	bIsActive = NewBoxState;
}

void AMyBox::WasCollected_Implementation()
{
	// Log a debug message
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}