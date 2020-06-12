// Copyright Artur Symanovic 2020


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	FRotator ClosedDoorRotation = GetOwner()->GetActorRotation();
	FRotator OpenedDoorRotation = ClosedDoorRotation;
	//FRotator OpenedDoorRotation = FRotator(ClosedDoorRotation);
	OpenedDoorRotation.Yaw += 90.f;
	UE_LOG(LogTemp, Warning, TEXT("ClosedDoorRotation Yaw: %f"), ClosedDoorRotation.Yaw);
	UE_LOG(LogTemp, Warning, TEXT("OpenedDoorRotation Yaw: %f"), OpenedDoorRotation.Yaw);
	
	GetOwner()->SetActorRotation(OpenedDoorRotation);
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

