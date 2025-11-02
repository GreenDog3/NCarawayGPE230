// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creates component
	visualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	visualMesh->SetupAttachment(RootComponent);

	
		visualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &AMazeCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotate);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMazeCharacter::DoJump);
}

void AMazeCharacter::MoveForward(float speed)
{
	AddMovementInput(GetActorForwardVector(), speed);
}

void AMazeCharacter::MoveRight(float speed)
{
	AddMovementInput(GetActorRightVector(), speed);
}

void AMazeCharacter::Rotate(float speed)
{
	AddControllerYawInput(speed);
}

void AMazeCharacter::DoJump()
{
	UE_LOG(LogTemp, Warning, TEXT("le jump"));
	Jump();
}

