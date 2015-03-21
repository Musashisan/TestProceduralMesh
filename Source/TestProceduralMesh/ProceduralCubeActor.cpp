// UE4 Procedural Mesh Generation from the Epic Wiki (https://wiki.unrealengine.com/Procedural_Mesh_Generation)
//
// A lathed object is a 3D model whose vertex geometry is produced by rotating a set of points around a fixed axis.
// (from Wikipedia http://en.wikipedia.org/wiki/Lathe_(graphics))

#include "TestProceduralMesh.h"
#include "ProceduralCubeActor.h"

AProceduralCubeActor::AProceduralCubeActor()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralCube"));

	// Apply a material
//	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("/Game/Test/Materials/M_CobbleStone_Rough"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("/Game/Test/Materials/M_Ground_Moss"));
	mesh->SetMaterial(0, Material.Object);


	float Size = 50;
	FVector Position(0, 0, 0);
	TArray<FProceduralMeshTriangle> triangles;

	// make vertex positions
	FVector p0 = FVector(Position.X, Position.Y, Position.Z);
	FVector p1 = FVector(Position.X, Position.Y, Position.Z + Size);
	FVector p2 = FVector(Position.X + Size, Position.Y, Position.Z + Size);
	FVector p3 = FVector(Position.X + Size, Position.Y, Position.Z);
	FVector p4 = FVector(Position.X + Size, Position.Y + Size, Position.Z);
	FVector p5 = FVector(Position.X + Size, Position.Y + Size, Position.Z + Size);
	FVector p6 = FVector(Position.X, Position.Y + Size, Position.Z + Size);
	FVector p7 = FVector(Position.X, Position.Y + Size, Position.Z);

	FProceduralMeshVertex v0;
	FProceduralMeshVertex v1;
	FProceduralMeshVertex v2;
	FProceduralMeshVertex v3;
	v0.U = 0; v0.V = 0;
	v1.U = 0; v1.V = .5;
	v2.U = .5; v2.V = .5;
	v3.U = .5; v3.V = 0;

	FProceduralMeshTriangle t1;
	FProceduralMeshTriangle t2;

	// front face
	v0.Position = p0;
	v1.Position = p1;
	v2.Position = p2;
	v3.Position = p3;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	//back face
	v0.Position = p4;
	v1.Position = p5;
	v2.Position = p6;
	v3.Position = p7;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// left face
	v0.Position = p7;
	v1.Position = p6;
	v2.Position = p1;
	v3.Position = p0;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// right face
	v0.Position = p3;
	v1.Position = p2;
	v2.Position = p5;
	v3.Position = p4;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// top face
	v0.Position = p1;
	v1.Position = p6;
	v2.Position = p5;
	v3.Position = p2;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// bottom face
	v0.Position = p3;
	v1.Position = p4;
	v2.Position = p7;
	v3.Position = p0;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	mesh->SetProceduralMeshTriangles(triangles);
	RootComponent = mesh;

}
