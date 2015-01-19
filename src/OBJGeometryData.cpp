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
		loadFileStatus.status = 2;
	}
	else
	{
		loadFileStatus.currentOperationName = "Parsing vertices...";
		loadFileStatus.currentOperationProgress = 0.0f;
		int totalVerticesCount = 0;
		for(size_t s = 0; s < shapes.size(); ++s)
		{
			totalVerticesCount += shapes[s].mesh.positions.size() / 3;
		}
		vertices = new OneDimensionalArray<Vertex>(totalVerticesCount);

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

				loadFileStatus.currentOperationProgress += 1.0f / totalVerticesCount;
			}
		}

		loadFileStatus.currentOperationName = "Found " + UnicodeString(totalVerticesCount) + " vertices.";

		loadFileStatus.currentOperationName = "Parsing faces...";
		loadFileStatus.currentOperationProgress = 0.0f;
		int totalFacesCount = 0;
		for(size_t s = 0; s < shapes.size(); ++s)
		{
			totalFacesCount += shapes[s].mesh.indices.size() / 3;
		}
		faces = new OneDimensionalArray<Face>(totalFacesCount);

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

				loadFileStatus.currentOperationProgress += 1.0f / totalFacesCount;
            }
		}

		loadFileStatus.currentOperationName = "Found " + UnicodeString(totalFacesCount) + " faces.";

    }
	loadFileStatus.status = 1;
}

DWORD WINAPI loadFileWrapper(LPVOID lpParameter)
{
	PtrAndString * ptrAndString = (PtrAndString *)lpParameter;
	ptrAndString->objGeometryData->loadFile(ptrAndString->filenameString);
	return 0;
}

void OBJGeometryData::saveFile(UnicodeString OBJFilename)
{
	UnicodeString outputString = "";
	UnicodeString lineBreak = "\r\n";

	outputString = outputString + "# OBJ geometry as re-saved by OBJ Solidizer And Voxelizer by Anton Martynov." + lineBreak;

	// Switching to the standard C locale for numerals (you'll be surprised
	// what (and why) can happen if you don't!)
	setlocale(LC_NUMERIC, "C");

	saveFileStatus.currentOperationName = "Writing vertices information...";
	saveFileStatus.currentOperationProgress = 0.0f;
	saveFileStatus.status = 0;
	for(int v = 0; v < vertices->getCount(); ++v)
	{
		outputString = outputString + "v " + UnicodeString(vertices->getElement(v)->x) + " " +
											 UnicodeString(vertices->getElement(v)->y) + " " +
											 UnicodeString(vertices->getElement(v)->z) + lineBreak;
		saveFileStatus.currentOperationProgress += 1.0f / vertices->getCount();
	}

	saveFileStatus.currentOperationName = "Writing indices information...";
	saveFileStatus.currentOperationProgress = 0.0f;
	saveFileStatus.status = 0;
	for(int f = 0; f < faces->getCount(); ++f)
	{
		outputString = outputString + "f " + UnicodeString(faces->getElement(f)->v1 + 1) + " " +
											 UnicodeString(faces->getElement(f)->v2 + 1) + " " +
											 UnicodeString(faces->getElement(f)->v3 + 1) + lineBreak;
		saveFileStatus.currentOperationProgress += 1.0f / faces->getCount();
	}

	// Switching back to system default locale for numerals
	setlocale(LC_NUMERIC, "");

	fileio::writeFile(OBJFilename, outputString);
}

DWORD WINAPI saveFileWrapper(LPVOID lpParameter)
{
	PtrAndString * ptrAndString = (PtrAndString *)lpParameter;
	ptrAndString->objGeometryData->saveFile(ptrAndString->filenameString);
	return 0;
}
