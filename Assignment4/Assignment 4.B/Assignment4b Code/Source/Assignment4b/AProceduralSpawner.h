#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AProceduralSpawner.generated.h"

UCLASS()
class ASSIGNMENT4B_API AProceduralSpawner : public AActor
{
    GENERATED_BODY()

public:
    AProceduralSpawner();

protected:
    virtual void OnConstruction(const FTransform& Transform) override;

public:
    UPROPERTY(EditAnywhere, Category = "Spawning")
    int32 SpawnCount = 30;

    UPROPERTY(EditAnywhere, Category = "Spawning")
    FVector SpawnExtent = FVector(2000, 2000, 200);

    UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<AActor> SpawnClass;
};