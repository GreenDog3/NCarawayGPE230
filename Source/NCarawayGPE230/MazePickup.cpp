// Fill out your copyright notice in the Description page of Project Settings.


#include "MazePickup.h"
#include "MazeCharacter.h"

AMazePickup::AMazePickup()
{
	OnActorBeginOverlap.AddDynamic(this, &AMazePickup::OnPickup); //when something overlaps, run OnPickup
}

void AMazePickup::OnPickup(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) //checks if the player is overlapping the key
	{
		ApplyPickup();
	}
}

void AMazePickup::ApplyPickup()
{
	//the effects might mostly b e done in blueprint? but i'd rather have this and not need it than need it and not have it

	//destroy pickup
	this->Destroy();
}
