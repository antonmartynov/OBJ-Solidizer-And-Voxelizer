#include "Engine.h"

Engine::Engine()
{
	//
}

Engine::~Engine()
{
	//
}

void Engine::initialize()
{
	geometryData = new OBJGeometryData();
	voxelizer = new Voxelizer();
}

DWORD WINAPI loadFileWrapper(LPVOID lpParameter)
{
	PtrAndString * ptrAndString = (PtrAndString *)lpParameter;
	ptrAndString->objGeometryData->loadFile(ptrAndString->filenameString);
	return 0;
}

void Engine::loadFile(UnicodeString filename)
{
	PtrAndString * ptrAndString = new PtrAndString;
	ptrAndString->objGeometryData = geometryData;
	ptrAndString->filenameString = filename;
	CreateThread(NULL, 0, loadFileWrapper, (void *)ptrAndString, 0, NULL);
}

DWORD WINAPI saveFileWrapper(LPVOID lpParameter)
{
	PtrAndString * ptrAndString = (PtrAndString *)lpParameter;
	ptrAndString->objGeometryData->saveFile(ptrAndString->filenameString);
	return 0;
}

void Engine::saveFile(UnicodeString filename)
{
	PtrAndString * ptrAndString = new PtrAndString;
	ptrAndString->objGeometryData = geometryData;
	ptrAndString->filenameString = filename;
	CreateThread(NULL, 0, saveFileWrapper, (void *)ptrAndString, 0, NULL);
}

void Engine::initVoxelizer()
{
	voxelizer->setGeometryData(geometryData);
}

DWORD WINAPI voxelizeWrapper(LPVOID lpParameter)
{
	Voxelizer * pVoxelizer = (Voxelizer *)lpParameter;
	pVoxelizer->process();
}

void Engine::voxelize()
{
	CreateThread(NULL, 0, voxelizeWrapper, (void *)voxelizer, 0, NULL);
}

void Engine::createOptimalGrid(float desiredStep)
{
	voxelizer->initVoxelGrid(voxelizer->computeOptimalGridDimensions(desiredStep));
}

void Engine::saveVoxelsAsCubeGeometry(UnicodeString filename/*, OperationStatus * progressTracking*/)
{
	OBJGeometryData * outputGeometryData = new OBJGeometryData();
	//progressTracking = &(outputGeometryData->saveFileStatus);
	outputGeometryData->generateFromVoxelGrid(voxelizer->voxelGrid);
	outputGeometryData->saveFile(filename);
	//delete outputGeometryData;
}
