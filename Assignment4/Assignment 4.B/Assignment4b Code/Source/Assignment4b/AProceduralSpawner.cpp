#include "AProceduralSpawner.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

AProceduralSpawner::AProceduralSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AProceduralSpawner::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    UWorld* World = GetWorld();
    if (!World || !SpawnClass) return;

    for (int i = 0; i < SpawnCount; i++)
    {
        FVector Location = UKismetMathLibrary::RandomPointInBoundingBox(
            GetActorLocation(), SpawnExtent);

        FRotator Rotation = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

        FActorSpawnParameters Params;
        World->SpawnActor<AActor>(SpawnClass, Location, Rotation, Params);
    }
}