// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PropPlayer.generated.h"

UCLASS()
class PROPHUNT_API APropPlayer : public APawn
{
	GENERATED_BODY()

private:

public:
	// Sets default values for this pawn's properties
	APropPlayer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
		
};
