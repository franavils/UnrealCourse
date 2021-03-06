// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION_03_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.0f;

	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	
	UInputComponent* InputComponent = nullptr;


	void Grab();
	void Release();
	void FindPhysicsComponent();
	void SetupInputComponent();
	FHitResult GetFirstPhysicsBodyInReach();
	
	// Returns start and end of line tracing
	FVector GetReachLineEnd();
	FVector GetReachLineStart();



		
	
};
