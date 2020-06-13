// Copyright Artur Symanovic 2020


#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewLocation, ViewRotation);	
	//UE_LOG(LogTemp, Warning, TEXT("View Location: %s"), *ViewLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("View Rotation: %s"), *ViewRotation.ToString());

	FVector LineTraceEnd = ViewLocation + FVector(0.f, 0.f, 100.f);
	LineTraceEnd = ViewLocation + ViewRotation.Vector() * 100.f;
	DrawDebugLine(
		GetWorld(),
		ViewLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false, 
		1.0f, 
		20,
		1.f
	);

}

