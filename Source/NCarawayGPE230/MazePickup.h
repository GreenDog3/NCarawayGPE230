// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MazePickup.generated.h"

/**
 * 
 */
UCLASS()
class NCARAWAYGPE230_API AMazePickup : public ATriggerBox
{
	GENERATED_BODY()
public:
	AMazePickup();

public:
	UFUNCTION()
	void OnPickup(class AActor* OverlappedActor, class AActor* OtherActor);
	void ApplyPickup();
};
