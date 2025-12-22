// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "VictoryBox.generated.h"

/**
 * 
 */
UCLASS()
class NCARAWAYGPE230_API AVictoryBox : public ATriggerBox
{
	GENERATED_BODY()
public:
	AVictoryBox();

public:
	UFUNCTION()
	void OnVictory(class AActor* OverlappedActor, class AActor* OtherActor);
	void Win();
	
};
