// Fill out your copyright notice in the Description page of Project Settings.

#include "PropHunt.h"
#include "Prop.h"


// Sets default values
AProp::AProp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (ModelToSet != nullptr) { 
		
		UE_LOG(LogTemp, Warning, TEXT("Prop model set!")); 	
		
		TArray<UStaticMeshComponent *> staticMeshComponents;		
		GetComponents(staticMeshComponents);

		if (staticMeshComponents[0]) {
		
			staticMeshComponents[0]->SetStaticMesh(ModelToSet);
		
		}

		else{ UE_LOG(LogTemp, Warning, TEXT("Error- a prop is missing a static mesh component")); }

	}

	else { UE_LOG(LogTemp, Warning, TEXT("Error- a prop is missing a model")); }

}

// Called when the game starts or when spawned
void AProp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

