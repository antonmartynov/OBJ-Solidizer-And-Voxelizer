#ifndef VoxelizerH
#define VoxelizerH

#include "OBJGeometryData.h"

class Voxelizer
{
public:

	Voxelizer();
	~Voxelizer();

	void setGeometryData(OBJGeometryData * newGeometryData);

private:

	OBJGeometryData * geometryData;
};

#endif
