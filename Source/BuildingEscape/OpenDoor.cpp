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
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	FRotator CurrentDoorRotation = GetOwner()->GetActorRotation();
	FRotator NextDoorRotation = FRotator(CurrentDoorRotation);
	float YawStep = FMath::FInterpTo(CurrentDoorRotation.Yaw, TargetYaw, DeltaTime, 1);
	NextDoorRotation.Yaw = YawStep;
	UE_LOG(LogTemp, Warning, TEXT("CurrentDoorRotation Yaw: %f"), CurrentDoorRotation.Yaw);
	UE_LOG(LogTemp, Warning, TEXT("NextDoorRotation Yaw: %f"), NextDoorRotation.Yaw);	
	GetOwner()->SetActorRotation(NextDoorRotation);		
}

