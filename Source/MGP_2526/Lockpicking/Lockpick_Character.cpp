// Fill out your copyright notice in the Description page of Project Settings.


#include "Lockpicking/Lockpick_Character.h"
#include "Camera/CameraComponent.h"

// Sets default values
ALockpick_Character::ALockpick_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Pick Cam"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALockpick_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALockpick_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALockpick_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Y",  this, &ALockpick_Character::MoveUp);
	PlayerInputComponent->BindAxis("X",  this, &ALockpick_Character::MoveRight);
}

void ALockpick_Character::MoveUp(float InputVector) 
{
	FVector UpDirection = GetActorUpVector();
	AddMovementInput(UpDirection, InputVector);

}

void ALockpick_Character::MoveRight(float InputVector)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputVector);
}

