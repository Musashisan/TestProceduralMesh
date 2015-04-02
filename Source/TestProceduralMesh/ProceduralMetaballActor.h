/*
*/

#pragma once

#include "GameFramework/Actor.h"
#include "MarchingCubes.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralMetaballActor.generated.h"

/**
*
*/
UCLASS()
class TESTPROCEDURALMESH_API AProceduralMetaballActor : public AActor
{
	GENERATED_BODY()

public:
	AProceduralMetaballActor();

	// Allow viewing/changing the Material ot the procedural Mesh in editor (if placed in a level at construction)
	UPROPERTY(VisibleAnywhere, Category = Materials)
		UProceduralMeshComponent* mesh;
private:

	const float threshold = 0.7;
	MarchingCubes *mcubes;
	int nBalls;
	TArray <FVector> balls;
	TArray <int16> ballsSize;

};