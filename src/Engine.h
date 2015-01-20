#ifndef EngineH
#define EngineH

#include "OBJGeometryData.h"
#include "Voxelizer.h"

class Engine
{
public:
	Engine();
	~Engine();

	void initialize();

	OBJGeometryData * geometryData;
	Voxelizer * voxelizer;

	void loadFile(UnicodeString filename);
	void saveFile(UnicodeString filename);

	void initVoxelizer();
};

#endif
