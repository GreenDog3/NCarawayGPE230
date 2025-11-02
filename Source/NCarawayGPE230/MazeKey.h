// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MazeDoor.h"
#include "MazeKey.generated.h"

/**
 * 
 */
UCLASS()
class NCARAWAYGPE230_API AMazeKey : public ATriggerBox
{
	GENERATED_BODY()
public:
	AMazeKey();
	UPROPERTY(EditAnywhere)
	AMazeDoor* doorToOpen;

public:
	UFUNCTION()
	void OnPickup(class AActor* OverlappedActor, class AActor* OtherActor);
	void OpenDoor();

};
