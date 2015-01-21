#ifndef VoxelizerH
#define VoxelizerH

#include "OBJGeometryData.h"
#include "VoxelGrid.h"
#include "math.h"

class Voxelizer
{
public:

	Voxelizer();
	~Voxelizer();

	void setGeometryData(OBJGeometryData * newGeometryData);
	Dimensions computeOptimalGridDimensions(float desiredStep);
	void initVoxelGrid(Dimensions dimensions);
	Dimensions getVoxelGridDimensions();

	void randomizeVoxelValues();

	OBJGeometryData * makeCubeGeometryFromVoxels();
	void setFaceForCubeGenerator(OneDimensionalArray<Face> * faces, int currentVoxelIndex, int faceIndexInCube, int v1, int v2, int v3);
	void generateCubeFromVoxel(int currentVoxelIndex, OBJGeometryData * recipientGeometry, Dimensions gridDimensions, int xIndex, int yIndex, int zIndex);

private:

	OBJGeometryData * geometryData;
	VoxelGrid * voxelGrid;
};

#endif
