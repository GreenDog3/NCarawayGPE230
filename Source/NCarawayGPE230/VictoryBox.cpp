// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryBox.h"
#include "MazeCharacter.h"

AVictoryBox::AVictoryBox()
{
	
}

void AVictoryBox::OnVictory(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) //checks if the player is overlapping the zone
	{
		Win();
	}
}

void AVictoryBox::Win()
{
	//effect will be done in blueprint

}
