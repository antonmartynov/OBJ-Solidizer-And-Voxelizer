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
}

void Engine::loadFile(UnicodeString filename)
{
	PtrAndString * ptrAndString = new PtrAndString;
	ptrAndString->objGeometryData = geometryData;
	ptrAndString->filenameString = filename;
	CreateThread(NULL, 0, loadFileWrapper, (void *)ptrAndString, 0, NULL);
}

void Engine::saveFile(UnicodeString filename)
{
	PtrAndString * ptrAndString = new PtrAndString;
	ptrAndString->objGeometryData = geometryData;
	ptrAndString->filenameString = filename;
	CreateThread(NULL, 0, saveFileWrapper, (void *)ptrAndString, 0, NULL);
}
