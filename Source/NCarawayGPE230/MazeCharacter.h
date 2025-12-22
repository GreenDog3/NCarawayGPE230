// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Blueprint/UserWidget.h"
#include "MazeCharacter.generated.h"

UCLASS()
class NCARAWAYGPE230_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* visualMesh;

private:
	UPROPERTY(EditAnywhere)
	float moveSpeed;
	UPROPERTY(EditAnywhere)
	float turnSpeed;
	UPROPERTY(EditAnywhere)
	float traceRadius = 500.0f;
	UPROPERTY(EditAnywhere)
	FName punchingSocketName;
	UPROPERTY(EditAnywhere)
	float hitDamage;
	UPROPERTY(EditAnywhere)
	UAnimSequence* deathAnim;
	UPROPERTY(EditAnywhere)
	bool isDoesHealth;
	
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* stunSystem;
	bool isDead = false;


public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Die();
public:	
	UPROPERTY(BlueprintReadOnly)
	float currentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isDoesWin;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float speed);
	void MoveRight(float speed);
	void Rotate(float speed);
	void DoJump();
	//void DoStun();
	UFUNCTION(BlueprintCallable, Category ="Collision")
	void DetectHit();
	UFUNCTION(BlueprintCallable)
	void ActivateStunParticleSystem();
};
