#ifndef OBJGeometryDataH
#define OBJGeometryDataH

#include "Vertex.h"
#include "Face.h"
#include "OneDimensionalArray.h"
#include "FileIO.h"
#include "tiny_obj_loader.h"

/*
Issues / TODO:
1. Needs proper return codes for loading / saving files
2. I might be better off using smth like std::string instead of UnicodeString
   (not sure, since filenames can be Unicode)
*/

struct operationStatus
{
	UnicodeString currentOperationName;
	float currentOperationProgress;
	int status; // 0 - in progress, 1 - finished, 2 - error (currentOperationName has description)
};

class OBJGeometryData
{
public:

	OBJGeometryData();
	~OBJGeometryData();

	void loadFile(UnicodeString OBJFilename);
	operationStatus loadFileStatus;
	void saveFile(UnicodeString OBJFilename);
	operationStatus saveFileStatus;

	friend DWORD WINAPI loadFileWrapper(LPVOID lpParameter);
	friend DWORD WINAPI saveFileWrapper(LPVOID lpParameter);

private:

	UnicodeString filename;
	OneDimensionalArray<Vertex> * vertices;
	OneDimensionalArray<Face> * faces;
};

struct PtrAndString
{
	OBJGeometryData * objGeometryData;
	UnicodeString filenameString;
};

#endif
