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
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 0)->x = currentXValue - halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 0)->y = currentYValue - halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 0)->z = currentZValue - halfStep;

					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 1)->x = currentXValue - halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 1)->y = currentYValue - halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 1)->z = currentZValue + halfStep;  

					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 2)->x = currentXValue - halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 2)->y = currentYValue + halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 2)->z = currentZValue - halfStep;  

					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 3)->x = currentXValue - halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 3)->y = currentYValue + halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 3)->z = currentZValue + halfStep;
					                                                                                                  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 4)->x = currentXValue + halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 4)->y = currentYValue - halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 4)->z = currentZValue - halfStep;

					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 5)->x = currentXValue + halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 5)->y = currentYValue - halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 5)->z = currentZValue + halfStep;  

					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 6)->x = currentXValue + halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 6)->y = currentYValue + halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 6)->z = currentZValue - halfStep;  

					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 7)->x = currentXValue + halfStep;     
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 7)->y = currentYValue + halfStep;  
					cubeGeometryData->vertices->getElement(currentVoxelIndex * 8 + 7)->z = currentZValue + halfStep;

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 0)->v1 = currentVoxelIndex * 8 + 0; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 0)->v2 = currentVoxelIndex * 8 + 1;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 0)->v3 = currentVoxelIndex * 8 + 2;  

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 1)->v1 = currentVoxelIndex * 8 + 1; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 1)->v2 = currentVoxelIndex * 8 + 3;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 1)->v3 = currentVoxelIndex * 8 + 2;    

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 2)->v1 = currentVoxelIndex * 8 + 1; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 2)->v2 = currentVoxelIndex * 8 + 5;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 2)->v3 = currentVoxelIndex * 8 + 3;    

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 3)->v1 = currentVoxelIndex * 8 + 5; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 3)->v2 = currentVoxelIndex * 8 + 7;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 3)->v3 = currentVoxelIndex * 8 + 3;      

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 4)->v1 = currentVoxelIndex * 8 + 5; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 4)->v2 = currentVoxelIndex * 8 + 4;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 4)->v3 = currentVoxelIndex * 8 + 7;      

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 5)->v1 = currentVoxelIndex * 8 + 4; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 5)->v2 = currentVoxelIndex * 8 + 6;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 5)->v3 = currentVoxelIndex * 8 + 7;       

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 6)->v1 = currentVoxelIndex * 8 + 4; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 6)->v2 = currentVoxelIndex * 8 + 0;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 6)->v3 = currentVoxelIndex * 8 + 6;       

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 7)->v1 = currentVoxelIndex * 8 + 0; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 7)->v2 = currentVoxelIndex * 8 + 2;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 7)->v3 = currentVoxelIndex * 8 + 6;        

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 8)->v1 = currentVoxelIndex * 8 + 2; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 8)->v2 = currentVoxelIndex * 8 + 3;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 8)->v3 = currentVoxelIndex * 8 + 6;        

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 9)->v1 = currentVoxelIndex * 8 + 3; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 9)->v2 = currentVoxelIndex * 8 + 7;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 9)->v3 = currentVoxelIndex * 8 + 6;        

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 10)->v1 = currentVoxelIndex * 8 + 4; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 10)->v2 = currentVoxelIndex * 8 + 5;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 10)->v3 = currentVoxelIndex * 8 + 0;        

					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 11)->v1 = currentVoxelIndex * 8 + 1; 
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 11)->v2 = currentVoxelIndex * 8 + 0;  
					cubeGeometryData->faces->getElement(currentVoxelIndex * 12 + 11)->v3 = currentVoxelIndex * 8 + 5;
					
					currentVoxelIndex++;
                }
			}
		}
	}

	cubeGeometryData->saveFile("P:\\alotofcubes.obj");
}
