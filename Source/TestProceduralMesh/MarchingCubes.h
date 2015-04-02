/*
asd
*/
#pragma once

#include "ProceduralMeshComponent.h"
//#include "MarchingCubes.generated.h"


class MarchingCubes {
public:

	//  Based on: http://paulbourke.net/geometry/polygonise/


	TArray<TArray<TArray<float>>> gridValues;
	TArray<TArray<TArray<FVector>>> gridPoints;

	float gridResolution = 2;
	float gridSizeX = 100;
	float gridSizeY = 100;
	float gridSizeZ = 100;


	MarchingCubes();
	void drawGridInPoints();
	void drawGridTriangles(TArray<FProceduralMeshTriangle> *tri);
	//void zeroGrid();

	// misc functions
	int getNumTriangles();

	// the heart of Marching Cubes
	void update(float threshold);
	void marchingCubes(int cubeX, int cubeY, int cubeZ, float threshold);
	void vertexInterpolation(float threshold, FVector4& p1, FVector4& p2, FVector& vertex);
	//	void v4Interpolation(float threshold, FVector4 v1, FVector4 v2, FVector4& vertex);
	//Iso Values
	void addMetaBall(FVector center, float charge);

	void getVec4(int index, int i, int j, int k, FVector4 &v);
	void getGradient(int index, int i, int j, int k, FVector4 &v);

private:

	FVector vertList[12];
	FVector4 gradients[12];
	FVector gradList[12];
	TArray<FVector> vertices;
	TArray<FVector> normals;
	int numTriangles;


};


