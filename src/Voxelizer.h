#ifndef VoxelizerH
#define VoxelizerH

#include "OBJGeometryData.h"
#include "VoxelGrid.h"
#include "math.h"
#include "OperationStatus.h"

class Voxelizer
{
public:

	Voxelizer();
	~Voxelizer();

	void setGeometryData(OBJGeometryData * newGeometryData);
	Dimensions computeOptimalGridDimensions(float desiredStep);
	void initVoxelGrid(Dimensions dimensions);
	Dimensions getVoxelGridDimensions();
	void process();
	operationStatus processStatus;

//private:

	OBJGeometryData * geometryData;
	VoxelGrid * voxelGrid;

	void randomizeVoxelValues();
};

#endif
