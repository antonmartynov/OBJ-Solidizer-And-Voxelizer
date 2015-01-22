#include "Voxelizer.h"

Voxelizer::Voxelizer()
{
	//
}

Voxelizer::~Voxelizer()
{
	//
}

void Voxelizer::setGeometryData(OBJGeometryData * newGeometryData)
{
	geometryData = newGeometryData;
}

Dimensions Voxelizer::computeOptimalGridDimensions(float desiredStep)
{
	float geometryLengthX = geometryData->spatialInformation.xMax - geometryData->spatialInformation.xMin;
	float geometryLengthY = geometryData->spatialInformation.yMax - geometryData->spatialInformation.yMin;
	float geometryLengthZ = geometryData->spatialInformation.zMax - geometryData->spatialInformation.zMin;

	float optimalLengthX = (float)(ceil(geometryLengthX / desiredStep)) * desiredStep;
	float optimalLengthY = (float)(ceil(geometryLengthY / desiredStep)) * desiredStep;
	float optimalLengthZ = (float)(ceil(geometryLengthZ / desiredStep)) * desiredStep;

	Dimensions optimalDimensions;

	optimalDimensions.x.start = geometryData->spatialInformation.xMin - (optimalLengthX - geometryLengthX) / 2;
	optimalDimensions.x.step = desiredStep;
	optimalDimensions.x.count = (int)(ceil(geometryLengthX / desiredStep)) + 1;
	optimalDimensions.y.start = geometryData->spatialInformation.yMin - (optimalLengthY - geometryLengthY) / 2;
	optimalDimensions.y.step = desiredStep;
	optimalDimensions.y.count = (int)(ceil(geometryLengthY / desiredStep)) + 1;
	optimalDimensions.z.start = geometryData->spatialInformation.zMin - (optimalLengthZ - geometryLengthZ) / 2;
	optimalDimensions.z.step = desiredStep;
	optimalDimensions.z.count = (int)(ceil(geometryLengthZ / desiredStep)) + 1;

	return optimalDimensions;
}

void Voxelizer::initVoxelGrid(Dimensions dimensions)
{
    voxelGrid = new VoxelGrid(dimensions);
}

Dimensions Voxelizer::getVoxelGridDimensions()
{
    return voxelGrid->getDimensions();
}

void Voxelizer::randomizeVoxelValues()
{
	randomize();
	processStatus.currentOperationName = "test";
	processStatus.currentOperationProgress = 0.2f;
	Dimensions dimensions = voxelGrid->getDimensions();
	bool *** data = voxelGrid->getData();
	for(int x = 0; x < dimensions.x.count; ++x)
	{
		for(int y = 0; y < dimensions.y.count; ++y)
		{
			for(int z = 0; z < dimensions.z.count; ++z)
			{
				data[x][y][z] = rand() % 2 == 0 ? false : true;
            }
        }
	}
	processStatus.currentOperationName = "test";
}

void Voxelizer::process()
{
	randomizeVoxelValues();
}
