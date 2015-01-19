#ifndef EngineH
#define EngineH

#include "OBJGeometryData.h"

class Engine
{
public:
	Engine();
	~Engine();

	void initialize();

	OBJGeometryData * geometryData;

	void loadFile(UnicodeString filename);
	void saveFile(UnicodeString filename);
};

#endif
