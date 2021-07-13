// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBox.generated.h"

UCLASS()
class CS380_FINAL_PROJECT_API AMyBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Return the mesh for the Box
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return MyBoxMesh; }

	// Return whether or not the Box is active
	UFUNCTION(BlueprintPure, Category = "MyBox")
	bool IsActive();

	// Allows other classes to safely change whether or not the Box is active
	UFUNCTION(BlueprintCallable, Category = "MyBox")
	void SetActive(bool NewBoxState);

	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:
	// True when the box can be used and false when it is deactivated
	bool bIsActive;

private:

	// Static Mesh to represent the box in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyBox", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MyBoxMesh;

};
