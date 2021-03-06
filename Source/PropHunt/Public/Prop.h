// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Prop.generated.h"

class UPropAttributesComponent;

UCLASS()
class PROPHUNT_API AProp : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AProp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere, Category = "Prop's Traits")
	int32 PropHealth = 100;
	
};
