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

private:

	OBJGeometryData * geometryData;
	VoxelGrid * voxelGrid;
};

#endif
