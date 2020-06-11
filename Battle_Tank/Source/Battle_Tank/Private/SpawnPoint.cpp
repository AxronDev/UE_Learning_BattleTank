// Copyright Euphoria Games LLT.


#include "SpawnPoint.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USpawnPoint::USpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	FTransform Pos = GetAttachParent()->GetSocketTransform(FName("Wheel1"));
	auto NewActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, Pos);
	UE_LOG(LogTemp, Warning, TEXT("After Spawn"))
	if (!NewActor) return;
	NewActor->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
	UGameplayStatics::FinishSpawningActor(NewActor, Pos);
}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

