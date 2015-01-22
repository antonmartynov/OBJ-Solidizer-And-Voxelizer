#ifndef OBJGeometryDataH
#define OBJGeometryDataH

#include "Vertex.h"
#include "Face.h"
#include "OneDimensionalArray.h"
#include "FileIO.h"
#include "tiny_obj_loader.h"
#include "float.h"
#include "VoxelGrid.h"
#include "OperationStatus.h"

/*
Issues / TODO:
1. Needs proper return codes for loading / saving files
2. I might be better off using smth like std::string instead of UnicodeString
   (not sure, since filenames can be Unicode)
*/

struct OBJInformation
{
	int verticesCount;
	int facesCount;
	float xMin;
	float xMax;
	float yMin;
	float yMax;
	float zMin;
	float zMax;
};

class OBJGeometryData
{
public:

	OBJGeometryData();
	~OBJGeometryData();

	OBJInformation spatialInformation;

	void loadFile(UnicodeString OBJFilename);
	OperationStatus loadFileStatus;
	void saveFile(UnicodeString OBJFilename);
	OperationStatus saveFileStatus;
	void generateFromVoxelGrid(VoxelGrid * voxelGrid);

private:

	UnicodeString filename;
	OneDimensionalArray<Vertex> * vertices;
	OneDimensionalArray<Face> * faces;

	void generateCubeFromVoxel(int voxelIndex, float halfStep, float xCoord, float yCoord, float zCoord);
	void setFaceForCubeGenerator(int voxelIndex, int faceIndexInCube, int v1, int v2, int v3);
};

struct PtrAndString
{
	OBJGeometryData * objGeometryData;
	UnicodeString filenameString;
};

#endif
