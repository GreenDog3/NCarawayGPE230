// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"
#include "MazeKey.h"


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
	//destroy door
	doorToOpen->Destroy();

	//destroy key
	this->Destroy();
}
