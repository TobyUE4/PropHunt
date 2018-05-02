// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "PropPC.generated.h"

class AProp;
class UPropPlayerAttributes;

/**
 * 
 */
UCLASS()
class PROPHUNT_API APropPC : public APlayerController
{
	GENERATED_BODY()

private:

	bool UseDebugLines = false;
	
public:

	UFUNCTION(BlueprintCallable, Category = "Prop Swapping")
	void BecomeProp();

	UFUNCTION(BlueprintCallable, Category = "Health Info")
	float GetHealthAsPercent();

	UFUNCTION(BlueprintCallable, Category = "Health Info")
	int32 GetHealthPoints();

};
