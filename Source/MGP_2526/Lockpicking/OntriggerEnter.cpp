// Fill out your copyright notice in the Description page of Project Settings.


#include "Lockpicking/OntriggerEnter.h"

AOntriggerEnter::AOntriggerEnter()
{
   
}

void AOntriggerEnter::BeginPlay()
{
    Super::BeginPlay();

    OnActorBeginOverlap.AddDynamic(this, &AOntriggerEnter::triggerEntered);
}

void AOntriggerEnter::triggerEntered(AActor* overlappedActor, AActor* otherActor)
{
    if (otherActor && otherActor != this)
    {
        UE_LOG(LogTemp, Warning, TEXT("Hello World"));
    }
}

