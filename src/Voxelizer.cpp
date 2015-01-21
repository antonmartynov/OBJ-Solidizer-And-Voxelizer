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
}

void Voxelizer::setFaceForCubeGenerator(OneDimensionalArray<Face> * faces, int currentVoxelIndex, int faceIndexInCube, int v1, int v2, int v3)
{
	faces->getElement(currentVoxelIndex * 12 + faceIndexInCube)->v1 = currentVoxelIndex * 8 + v1;
	faces->getElement(currentVoxelIndex * 12 + faceIndexInCube)->v2 = currentVoxelIndex * 8 + v2;
	faces->getElement(currentVoxelIndex * 12 + faceIndexInCube)->v3 = currentVoxelIndex * 8 + v3;
}

void Voxelizer::generateCubeFromVoxel(int currentVoxelIndex, OBJGeometryData * recipientGeometry, Dimensions gridDimensions, int xIndex, int yIndex, int zIndex)
{
	float currentXValue = gridDimensions.getXValue(xIndex);
	float currentYValue = gridDimensions.getYValue(yIndex);
	float currentZValue = gridDimensions.getZValue(zIndex);
	float halfStep = gridDimensions.x.step / 2;
	for(int v = 0; v < 8; ++v)
	{
		// procedural generation of cube vertices
		Vertex * pVertex = recipientGeometry->vertices->getElement(currentVoxelIndex * 8 + v);
		pVertex->x = currentXValue + halfStep * ((v & (1<<2)) ? 1 : (-1));
		pVertex->y = currentYValue + halfStep * ((v & (1<<1)) ? 1 : (-1));
		pVertex->z = currentZValue + halfStep * ((v & (1<<0)) ? 1 : (-1));
	}
	// unfortunately, cube faces can't be procedurally generated
	OneDimensionalArray<Face> * pFaces = recipientGeometry->faces;
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 0, 0, 1, 2);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 1, 1, 3, 2);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 2, 1, 5, 3);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 3, 5, 7, 3);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 4, 5, 4, 7);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 5, 4, 6, 7);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 6, 4, 0, 6);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 7, 0, 2, 6);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 8, 2, 3, 6);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 9, 3, 7, 6);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 10, 4, 5, 0);
	setFaceForCubeGenerator(pFaces, currentVoxelIndex, 11, 1, 0, 5);

}

OBJGeometryData * Voxelizer::makeCubeGeometryFromVoxels()
{
	OBJGeometryData * cubeGeometryData = new OBJGeometryData();
	int voxelCount = 0;
	for(int x = 0; x < voxelGrid->getDimensions().x.count; ++x)
	{
		for(int y = 0; y < voxelGrid->getDimensions().y.count; ++y)
		{
			for(int z = 0; z < voxelGrid->getDimensions().z.count; ++z)
			{
				if(voxelGrid->getData()[x][y][z] == true)
				{
					voxelCount++;
				}
			}
		}
	}
	cubeGeometryData->spatialInformation.verticesCount = voxelCount * 8;
	cubeGeometryData->vertices = new OneDimensionalArray<Vertex>(cubeGeometryData->spatialInformation.verticesCount);
	cubeGeometryData->spatialInformation.facesCount = voxelCount * 12;
	cubeGeometryData->faces = new OneDimensionalArray<Face>(cubeGeometryData->spatialInformation.facesCount);
	
	int currentVoxelIndex = 0;
	for(int x = 0; x < voxelGrid->getDimensions().x.count; ++x)
	{
		for(int y = 0; y < voxelGrid->getDimensions().y.count; ++y)
		{
			for(int z = 0; z < voxelGrid->getDimensions().z.count; ++z)
			{
				float currentXValue = voxelGrid->getDimensions().getXValue(x);
				float currentYValue = voxelGrid->getDimensions().getYValue(y);
				float currentZValue = voxelGrid->getDimensions().getZValue(z);
				float halfStep = voxelGrid->getDimensions().x.step / 2;
				if(voxelGrid->getData()[x][y][z] == true)
				{
					generateCubeFromVoxel(currentVoxelIndex, cubeGeometryData, voxelGrid->getDimensions(), x, y, z);
					currentVoxelIndex++;
				}
			}
		}
	}

	cubeGeometryData->saveFile("P:\\alotofcubes.obj");
}
