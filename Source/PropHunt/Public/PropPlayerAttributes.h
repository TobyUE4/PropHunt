// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PropPlayerAttributes.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPHUNT_API UPropPlayerAttributes : public UActorComponent
{
	GENERATED_BODY()

private:

	int32 ExpectedMaxHealth = 200;
	int32 TypicalMaxHealth = 100;
	int32 CurrentHealth = 100;

public:	
	// Sets default values for this component's properties
	UPropPlayerAttributes();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	float GetHealthAsPercent();
	void SetHealth(int32 HealthToSet);
	int32 GetHP();
	
};
