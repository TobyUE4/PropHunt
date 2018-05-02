// Fill out your copyright notice in the Description page of Project Settings.

#include "PropHunt.h"
#include "Prop.h"
#include "PropAttributesComponent.h"
#include "PropPlayerAttributes.h"
#include "PropPC.h"


void APropPC::BecomeProp() {

	UE_LOG(LogTemp, Warning, TEXT("You want to become a prop"));

	int32 ViewportX, ViewPortY;
	GetViewportSize(ViewportX, ViewPortY);

	FVector2D ScreenLocation = FVector2D((ViewportX * .50), (ViewPortY * .50));

	FVector WorldDirection;
	FVector WorldLocation;

	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (WorldDirection * 100000);

	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_GameTraceChannel1)) {
	
		AActor * FoundProp = HitResult.GetActor();

		if (FoundProp) {
		
			TArray<UStaticMeshComponent *> PropStaticMeshComponents;
			TArray<UStaticMeshComponent *> MyStaticMeshComponents;
			
			TArray<UPropAttributesComponent *> PropAttributes;
			TArray<UPropPlayerAttributes *> MyAttributes;
			
			FoundProp->GetComponents(PropStaticMeshComponents);
			FoundProp->GetComponents(PropAttributes);

			if (PropStaticMeshComponents[0]) {
			
				UStaticMesh * MeshToInherit = PropStaticMeshComponents[0]->StaticMesh;	

				GetPawn()->GetComponents(MyStaticMeshComponents);
				GetPawn()->GetComponents(MyAttributes);

				if (MyStaticMeshComponents[0]) {
				
					if(MeshToInherit){ 
					
						MyStaticMeshComponents[0]->SetStaticMesh(MeshToInherit);
					
					}

				}

				else { UE_LOG(LogTemp, Warning, TEXT("Your pawn is missing a static mesh component!")); }

			}

			else { UE_LOG(LogTemp, Warning, TEXT("A prop is missing a static mesh component!")); }

			if (PropAttributes.Num() > 0) {

				if (PropAttributes[0]) {

					if (MyAttributes.Num() > 0) {

						if (MyAttributes[0]) {
							
							MyAttributes[0] -> SetHealth(PropAttributes[0]->InheritableHealth);

						}

					}

				}

			}

		}
	
	}
	
	if (UseDebugLines) {
		
		DrawDebugLine(

			GetWorld(),
			StartLocation,
			EndLocation,
			FColor(255, 0, 0),
			true,
			8.f,
			0,
			1.f

			);

	}

}

float APropPC::GetHealthAsPercent() {

	TArray <UPropPlayerAttributes *> MyAttributes;
	GetPawn()->GetComponents(MyAttributes);

	if (MyAttributes.Num() > 0) {
	
		if (MyAttributes[0]) { return MyAttributes[0]->GetHealthAsPercent(); }
	
		return 1.0;

	}

	return 1.0;

}

int32 APropPC::GetHealthPoints() {

	TArray <UPropPlayerAttributes *> MyAttributes;
	GetPawn()->GetComponents(MyAttributes);

	if (MyAttributes.Num() > 0) {

		if (MyAttributes[0]) { return MyAttributes[0]->GetHP(); }

		return 100;

	}

	return 100;

}
