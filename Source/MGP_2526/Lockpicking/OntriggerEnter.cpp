// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PrimitiveComponent.h"
#include "Lockpicking/OntriggerEnter.h"

AOntriggerEnter::AOntriggerEnter()
{
     pinsPushed = 0;
   
}

void AOntriggerEnter::BeginPlay()
{
    Super::BeginPlay();

    OnActorBeginOverlap.AddDynamic(this, &AOntriggerEnter::triggerEntered);
}

void AOntriggerEnter::triggerEntered(AActor* overlappedActor, AActor* otherActor)
{
    TArray<UPrimitiveComponent*> primComps;
    otherActor->GetComponents<UPrimitiveComponent>(primComps);

    for (UPrimitiveComponent* comp : primComps)
    {
        if (comp && comp->IsSimulatingPhysics())
        {
            comp->SetPhysicsLinearVelocity(FVector::ZeroVector);
            comp->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
            comp->SetSimulatePhysics(false);

             pinsPushed = pinsPushed + 1;
            if (pinsPushed>=4) 
            {
                if (Door)
                {
                    Door->Destroy();
                    Door = nullptr;
                }
            }


        }

    }
}

