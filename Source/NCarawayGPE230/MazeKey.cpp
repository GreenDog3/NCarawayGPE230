// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeKey.h"
#include "MazeCharacter.h"



AMazeKey::AMazeKey()
{
	OnActorBeginOverlap.AddDynamic(this, &AMazeKey::OnPickup); //when something overlaps, run OnPickup
}

void AMazeKey::OnPickup(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) //checks if the player is overlapping the key
	{
		OpenDoor();
	}
}

void AMazeKey::OpenDoor()
{
	if (doorToOpen)
	{
		//destroy door
		doorToOpen->Destroy();

		//destroy key
		this->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("A key with no door? HEY! GET ME A KEY WITH NOTHIN'!"));
		UE_LOG(LogTemp, Error, TEXT("A key with nothin'???"));
	}

}