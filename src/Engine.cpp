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
	geometryData->loadFile(filename);
}

void Engine::saveFile(UnicodeString filename)
{
	geometryData->saveFile(filename);
}
