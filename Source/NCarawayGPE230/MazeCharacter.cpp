// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

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
	currentHealth = maxHealth;
	
}

float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!isDead)
	{
		currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("Player was SLAMMED with %f POINTS of RAW DAMAGE!!! Only %f PITIFUL POINTS of HEALTH stand between the PLAYER and CERTAIN DEATH"), DamageAmount, currentHealth);
		if (currentHealth <= 0.0f)
		{
			Die();
		}
		return DamageAmount;
	}
	else
	{
		return 0;
	}
}


void AMazeCharacter::Die()
{
	isDead = true;
	currentHealth = 0;
	moveSpeed = 0;
	turnSpeed = 0;
	UE_LOG(LogTemp, Log, TEXT("Player has DIED a HORRIBLE and PAINFUL DEATH"));
	GetMesh()->PlayAnimation(deathAnim, false);
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
	PlayerInputComponent->BindAction(TEXT("Stun"), IE_Pressed, this, & AMazeCharacter::DoStun);
}

void AMazeCharacter::MoveForward(float speed)
{
	AddMovementInput(GetActorForwardVector(), speed * moveSpeed);
}

void AMazeCharacter::MoveRight(float speed)
{
	AddMovementInput(GetActorRightVector(), speed * moveSpeed);
}

void AMazeCharacter::Rotate(float speed)
{
	AddControllerYawInput(speed * turnSpeed);
}

void AMazeCharacter::DoJump()
{
	UE_LOG(LogTemp, Warning, TEXT("le jump"));
	Jump();
}

void AMazeCharacter::DoStun()
{
	//get all characters in a radius
	//call their stun events
}

void AMazeCharacter::DetectHit()
{
	bool canDamage = true;
	const FVector punchLocation = GetMesh()->GetSocketLocation(punchingSocketName);

	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(this);
	actorsToIgnore.Add(GetOwner());
	TArray<FHitResult> hitArray;

	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), punchLocation, punchLocation, traceRadius, UEngineTypes::ConvertToTraceType(ECC_Camera), false, actorsToIgnore, EDrawDebugTrace::None, hitArray, true, FLinearColor::Red,FLinearColor::Green,2.0f);

	FString ownerName = this->GetName();

	if (Hit)
	{
		for (const FHitResult hitResult : hitArray)
		{
			if (canDamage)
			{
				FString hitVictimName = hitResult.GetActor()->GetName();

				UE_LOG(LogTemp, Log, TEXT("Enemy actor \"%s\" SLAMS \"%s\" with %f POINTS of DAMAGE!!!"), *ownerName, *hitVictimName, hitDamage);
				UGameplayStatics::ApplyDamage(hitResult.GetActor(), hitDamage, GetController(), this, UDamageType::StaticClass());
				canDamage = false;
			}
		}
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("Enemy actor \"%s\" pathetically failed to achieve anything meaningful with their last attack!"), *ownerName);
	}


}

