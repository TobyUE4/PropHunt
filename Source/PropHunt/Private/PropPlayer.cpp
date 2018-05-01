// Fill out your copyright notice in the Description page of Project Settings.

#include "PropHunt.h"
#include "PropPlayer.h"


// Sets default values
APropPlayer::APropPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APropPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APropPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APropPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

