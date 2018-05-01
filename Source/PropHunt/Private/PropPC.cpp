// Fill out your copyright notice in the Description page of Project Settings.

#include "PropHunt.h"
#include "Prop.h"
#include "PropPC.h"


void APropPC::BecomeProp() {

	UE_LOG(LogTemp, Warning, TEXT("You want to become a prop"));

	int32 ViewportX, ViewPortY;
	GetViewportSize(ViewportX, ViewPortY);

	FVector2D ScreenLocation = FVector2D((ViewportX * .5), ((ViewPortY * .58) - 20));

	FVector WorldDirection;
	FVector WorldLocation;

	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (WorldDirection * 100000);

	DrawDebugLine(

		GetWorld(),
		StartLocation,
		EndLocation,
		FColor(255, 0, 0),
		true,
		60.f,
		0,
		1.f

	);

}

