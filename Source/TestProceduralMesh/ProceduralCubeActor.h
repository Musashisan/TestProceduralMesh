#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralCubeActor.generated.h"

/**
*
*/
UCLASS()
class TESTPROCEDURALMESH_API AProceduralCubeActor : public AActor
{
	GENERATED_BODY()

public:
	AProceduralCubeActor();

	// Allow viewing/changing the Material ot the procedural Mesh in editor (if placed in a level at construction)
	UPROPERTY(VisibleAnywhere, Category = Materials)
		UProceduralMeshComponent* mesh;

};