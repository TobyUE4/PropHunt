// Fill out your copyright notice in the Description page of Project Settings.

#include "PropHunt.h"
#include "PropPlayerAttributes.h"


// Sets default values for this component's properties
UPropPlayerAttributes::UPropPlayerAttributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPropPlayerAttributes::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPropPlayerAttributes::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}


void UPropPlayerAttributes::SetHealth(int32 HealthToSet) { 
	
	CurrentHealth = HealthToSet;  

	UE_LOG(LogTemp, Warning, TEXT("Health inherited: %i"), HealthToSet);

}

float UPropPlayerAttributes::GetHealthAsPercent() { 

	UE_LOG(LogTemp, Warning, TEXT("Current Player Health: %i"), CurrentHealth);

	if (CurrentHealth > TypicalMaxHealth && CurrentHealth <= ExpectedMaxHealth) { 
		
		UE_LOG(LogTemp, Warning, TEXT("Current Player Health as percent1: %f"), (CurrentHealth / ExpectedMaxHealth));

		return CurrentHealth / float(ExpectedMaxHealth);

	}

	else if (CurrentHealth > ExpectedMaxHealth) {
	
		CurrentHealth = ExpectedMaxHealth;
		UE_LOG(LogTemp, Warning, TEXT("Current Player Health as percent2: %f"), (CurrentHealth / ExpectedMaxHealth));
		return CurrentHealth / float(ExpectedMaxHealth);

	}

	else {

		UE_LOG(LogTemp, Warning, TEXT("Current Player Health as percent3: %f"), (CurrentHealth / float(TypicalMaxHealth)));
		return (CurrentHealth / float(TypicalMaxHealth));

	}

}

int32 UPropPlayerAttributes::GetHP() { return CurrentHealth;  }