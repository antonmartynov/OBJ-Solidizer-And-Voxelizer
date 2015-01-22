#include "OBJGeometryData.h"

OBJGeometryData::OBJGeometryData()
{
	filename = "";
}

OBJGeometryData::~OBJGeometryData()
{
	//
}

void OBJGeometryData::loadFile(UnicodeString OBJFilename)
{
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	loadFileStatus.currentOperationName = "Loading the file using Tiny OBJ Loader...";
	loadFileStatus.currentOperationProgress = 0.5f;
	loadFileStatus.overallProgress = 0.0f;
	loadFileStatus.status = 0;

	// Switching to the standard C locale for numerals (you'll be surprised
	// what (and why) can happen if you don't!)
	setlocale(LC_NUMERIC, "C");
	std::string error = tinyobj::LoadObj(shapes, materials, OBJFilename.t_str());
	// Switching back to system default locale for numerals
	setlocale(LC_NUMERIC, "");

	if(!error.empty())
	{
		loadFileStatus.currentOperationName = "ERROR! Tiny OBJ Loader's message: " + UnicodeString(error.c_str());
		loadFileStatus.currentOperationProgress = 0.0f;
		loadFileStatus.overallProgress = 0.0f;
		loadFileStatus.status = 2;
	}
	else
	{
		loadFileStatus.currentOperationName = "Counting vertices and indices...";
		loadFileStatus.currentOperationProgress = 0.5f;
		loadFileStatus.overallProgress = 0.0f;

		spatialInformation.verticesCount = 0;
		for(size_t s = 0; s < shapes.size(); ++s)
		{
			spatialInformation.verticesCount += shapes[s].mesh.positions.size() / 3;
		}
		vertices = new OneDimensionalArray<Vertex>(spatialInformation.verticesCount);

		spatialInformation.facesCount = 0;
		for(size_t s = 0; s < shapes.size(); ++s)
		{
			spatialInformation.facesCount += shapes[s].mesh.indices.size() / 3;
		}
		faces = new OneDimensionalArray<Face>(spatialInformation.facesCount);

		loadFileStatus.currentOperationName = "Parsing vertices...";

		double dblCurrentElapsedIterations = 0.0;
		double dblCurrentTotalIterations = (double)(spatialInformation.verticesCount);
		double dblOverallElapsedIterations = 0.0;
		double dblOverallTotalIterations = (double)(2 * spatialInformation.verticesCount + spatialInformation.facesCount);

		for(size_t s = 0; s < shapes.size(); ++s)
		{
			int verticesIndexOffset = 0;
			int currentAddedShape = 0;
			while(currentAddedShape < (int)s)
			{
				verticesIndexOffset += shapes[currentAddedShape].mesh.positions.size() / 3;
				currentAddedShape++;
            }
			for(size_t v = 0; v < shapes[s].mesh.positions.size() / 3; ++v)
			{
				vertices->getElement(verticesIndexOffset + v)->x =
				shapes[s].mesh.positions[v * 3 + 0];
				vertices->getElement(verticesIndexOffset + v)->y =
				shapes[s].mesh.positions[v * 3 + 1];
				vertices->getElement(verticesIndexOffset + v)->z =
				shapes[s].mesh.positions[v * 3 + 2];

				dblCurrentElapsedIterations += 1.0;
				dblOverallElapsedIterations += 1.0;
				loadFileStatus.currentOperationProgress = (float)(dblCurrentElapsedIterations / dblCurrentTotalIterations);
				loadFileStatus.overallProgress = (float)(dblOverallElapsedIterations / dblOverallTotalIterations);
			}
		}

		dblCurrentElapsedIterations = 0.0;
		dblCurrentTotalIterations = (double)(spatialInformation.facesCount);

		loadFileStatus.currentOperationName = "Parsing faces...";

		for(size_t s = 0; s < shapes.size(); ++s)
		{
			int verticesIndexOffset = 0;
			int facesIndexOffset = 0;
			int currentAddedShape = 0;
			while(currentAddedShape < (int)s)
			{
				verticesIndexOffset += shapes[currentAddedShape].mesh.positions.size() / 3;
				facesIndexOffset += shapes[currentAddedShape].mesh.indices.size() / 3;
				currentAddedShape++;
			}
			for(size_t i = 0; i < shapes[s].mesh.indices.size() / 3; ++i)
			{
				faces->getElement(facesIndexOffset + i)->v1 = verticesIndexOffset + shapes[s].mesh.indices[i * 3 + 0];
				faces->getElement(facesIndexOffset + i)->v2 = verticesIndexOffset + shapes[s].mesh.indices[i * 3 + 1];
				faces->getElement(facesIndexOffset + i)->v3 = verticesIndexOffset + shapes[s].mesh.indices[i * 3 + 2];

				dblCurrentElapsedIterations += 1.0;
				dblOverallElapsedIterations += 1.0;
				loadFileStatus.currentOperationProgress = (float)(dblCurrentElapsedIterations / dblCurrentTotalIterations);
				loadFileStatus.overallProgress = (float)(dblOverallElapsedIterations / dblOverallTotalIterations);
			}
		}

		dblCurrentElapsedIterations = 0.0;
		dblCurrentTotalIterations = (double)(spatialInformation.verticesCount);

		loadFileStatus.currentOperationName = "Computing the bounding box...";

		spatialInformation.xMin = FLT_MAX;
		spatialInformation.xMax = FLT_MIN;
		spatialInformation.yMin = FLT_MAX;
		spatialInformation.yMax = FLT_MIN;
		spatialInformation.zMin = FLT_MAX;
		spatialInformation.zMax = FLT_MIN;

		for(int v = 0; v < spatialInformation.verticesCount; ++v)
		{
			if(vertices->getElement(v)->x < spatialInformation.xMin)
			{
				spatialInformation.xMin = vertices->getElement(v)->x;
			}
			if(vertices->getElement(v)->x > spatialInformation.xMax)
			{
				spatialInformation.xMax = vertices->getElement(v)->x;
			}
			if(vertices->getElement(v)->y < spatialInformation.yMin)
			{
				spatialInformation.yMin = vertices->getElement(v)->y;
			}
			if(vertices->getElement(v)->y > spatialInformation.yMax)
			{
				spatialInformation.yMax = vertices->getElement(v)->y;
			}
			if(vertices->getElement(v)->z < spatialInformation.zMin)
			{
				spatialInformation.zMin = vertices->getElement(v)->z;
			}
			if(vertices->getElement(v)->z > spatialInformation.zMax)
			{
				spatialInformation.zMax = vertices->getElement(v)->z;
			}

			dblCurrentElapsedIterations += 1.0;
			dblOverallElapsedIterations += 1.0;
			loadFileStatus.currentOperationProgress = (float)(dblCurrentElapsedIterations / dblCurrentTotalIterations);
			loadFileStatus.overallProgress = (float)(dblOverallElapsedIterations / dblOverallTotalIterations);
        }

		loadFileStatus.currentOperationName = "Done!";
		loadFileStatus.status = 1;
	}
}

void OBJGeometryData::saveFile(UnicodeString OBJFilename)
{
	UnicodeString outputString = "";
	UnicodeString lineBreak = "\r\n";

	outputString = outputString + "# OBJ geometry as re-saved by OBJ Solidizer And Voxelizer by Anton Martynov." + lineBreak;

	// Switching to the standard C locale for numerals (you'll be surprised
	// what (and why) can happen if you don't!)
	setlocale(LC_NUMERIC, "C");

	double dblCurrentElapsedIterations = 0.0;
	double dblCurrentTotalIterations = (double)(vertices->getCount());
	double dblOverallElapsedIterations = 0.0;
	double dblOverallTotalIterations = (double)(vertices->getCount() + faces->getCount());

	saveFileStatus.currentOperationName = "Writing vertices information...";
	saveFileStatus.status = 0;
	for(int v = 0; v < vertices->getCount(); ++v)
	{
		outputString = outputString + "v " + UnicodeString(vertices->getElement(v)->x) + " " +
											 UnicodeString(vertices->getElement(v)->y) + " " +
											 UnicodeString(vertices->getElement(v)->z) + lineBreak;

		dblCurrentElapsedIterations += 1.0;
		dblOverallElapsedIterations += 1.0;
		saveFileStatus.currentOperationProgress = (float)(dblCurrentElapsedIterations / dblCurrentTotalIterations);
		saveFileStatus.overallProgress = (float)(dblOverallElapsedIterations / dblOverallTotalIterations);
	}

	dblCurrentElapsedIterations = 0.0;
	dblCurrentTotalIterations = (double)(faces->getCount());

	saveFileStatus.currentOperationName = "Writing indices information...";
	saveFileStatus.status = 0;
	for(int f = 0; f < faces->getCount(); ++f)
	{
		outputString = outputString + "f " + UnicodeString(faces->getElement(f)->v1 + 1) + " " +
											 UnicodeString(faces->getElement(f)->v2 + 1) + " " +
											 UnicodeString(faces->getElement(f)->v3 + 1) + lineBreak;

		dblCurrentElapsedIterations += 1.0;
		dblOverallElapsedIterations += 1.0;
		saveFileStatus.currentOperationProgress = (float)(dblCurrentElapsedIterations / dblCurrentTotalIterations);
		saveFileStatus.overallProgress = (float)(dblOverallElapsedIterations / dblOverallTotalIterations);
	}

	// Switching back to system default locale for numerals
	setlocale(LC_NUMERIC, "");

	saveFileStatus.currentOperationName = "Writing the OBJ contents to file...";
	saveFileStatus.currentOperationProgress = 0.5f;

	fileio::writeFile(OBJFilename, outputString);

	saveFileStatus.currentOperationProgress = 1.0f;

	saveFileStatus.currentOperationName = "Done!";
	saveFileStatus.status = 1;
}

void OBJGeometryData::generateFromVoxelGrid(VoxelGrid * voxelGrid)
{
	int filledVoxelsCount = 0;
	for(int x = 0; x < voxelGrid->getDimensions().x.count; ++x)
	{
		for(int y = 0; y < voxelGrid->getDimensions().y.count; ++y)
		{
			for(int z = 0; z < voxelGrid->getDimensions().z.count; ++z)
			{
				if(voxelGrid->getData()[x][y][z] == true)
				{
					filledVoxelsCount++;
				}
			}
		}
	}
	spatialInformation.verticesCount = filledVoxelsCount * 8;
	vertices = new OneDimensionalArray<Vertex>(spatialInformation.verticesCount);
	spatialInformation.facesCount = filledVoxelsCount * 12;
	faces = new OneDimensionalArray<Face>(spatialInformation.facesCount);

	int currentVoxelIndex = 0;
	for(int x = 0; x < voxelGrid->getDimensions().x.count; ++x)
	{
		for(int y = 0; y < voxelGrid->getDimensions().y.count; ++y)
		{
			for(int z = 0; z < voxelGrid->getDimensions().z.count; ++z)
			{
				if(voxelGrid->getData()[x][y][z] == true)
				{
					float xCoord = voxelGrid->getDimensions().getXValue(x);
					float yCoord = voxelGrid->getDimensions().getYValue(y);
					float zCoord = voxelGrid->getDimensions().getZValue(z);
					float halfStep = voxelGrid->getDimensions().x.step / 2;
					generateCubeFromVoxel(currentVoxelIndex, halfStep, xCoord, yCoord, zCoord);
					currentVoxelIndex++;
				}
			}
		}
	}
}

void OBJGeometryData::generateCubeFromVoxel(int voxelIndex, float halfStep, float xCoord, float yCoord, float zCoord)
{
	// procedural generation of cube vertices
	for(int v = 0; v < 8; ++v)
	{
		Vertex * pVertex = vertices->getElement(voxelIndex * 8 + v);
		pVertex->x = xCoord + halfStep * ((v & (1<<2)) ? 1 : (-1));
		pVertex->y = yCoord + halfStep * ((v & (1<<1)) ? 1 : (-1));
		pVertex->z = zCoord + halfStep * ((v & (1<<0)) ? 1 : (-1));
	}
	// unfortunately, cube faces cannot be procedurally generated
	setFaceForCubeGenerator(voxelIndex,  0, 0, 1, 2);
	setFaceForCubeGenerator(voxelIndex,  1, 1, 3, 2);
	setFaceForCubeGenerator(voxelIndex,  2, 1, 5, 3);
	setFaceForCubeGenerator(voxelIndex,  3, 5, 7, 3);
	setFaceForCubeGenerator(voxelIndex,  4, 5, 4, 7);
	setFaceForCubeGenerator(voxelIndex,  5, 4, 6, 7);
	setFaceForCubeGenerator(voxelIndex,  6, 4, 0, 6);
	setFaceForCubeGenerator(voxelIndex,  7, 0, 2, 6);
	setFaceForCubeGenerator(voxelIndex,  8, 2, 3, 6);
	setFaceForCubeGenerator(voxelIndex,  9, 3, 7, 6);
	setFaceForCubeGenerator(voxelIndex, 10, 4, 5, 0);
	setFaceForCubeGenerator(voxelIndex, 11, 1, 0, 5);
}

void OBJGeometryData::setFaceForCubeGenerator(int voxelIndex, int faceIndexInCube, int v1, int v2, int v3)
{
	faces->getElement(voxelIndex * 12 + faceIndexInCube)->v1 = voxelIndex * 8 + v1;
	faces->getElement(voxelIndex * 12 + faceIndexInCube)->v2 = voxelIndex * 8 + v2;
	faces->getElement(voxelIndex * 12 + faceIndexInCube)->v3 = voxelIndex * 8 + v3;
}
