// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "OntriggerEnter.generated.h"

/**
 * 
 */
UCLASS()
class MGP_2526_API AOntriggerEnter : public ATriggerBox
{
	GENERATED_BODY()

public:
	AOntriggerEnter();
	UPROPERTY(EditAnywhere)
	AActor* Door;
	UPROPERTY()
	int pinsPushed;
	UFUNCTION()
	void triggerEntered(AActor*overlappedActor , AActor*otherActor);
protected:
	virtual void BeginPlay() override;

	
};
