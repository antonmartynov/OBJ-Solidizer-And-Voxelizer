#include "VoxelGrid.h"

VoxelGrid::VoxelGrid(Dimensions initDimensions)
{
	setDimensions(initDimensions);
	allocate();
}

VoxelGrid::~VoxelGrid()
{
	deallocate();
}

void VoxelGrid::setDimensions(Dimensions initDimensions)
{
	dimensions = initDimensions;
}

void VoxelGrid::allocate()
{
	data = new bool ** [dimensions.x.count];
	for(int x = 0; x < dimensions.x.count; ++x)
	{
		data[x] = new bool * [dimensions.y.count];
		for(int y = 0; y < dimensions.y.count; ++y)
		{
			data[x][y] = new bool [dimensions.z.count];
        }
    }
}

void VoxelGrid::deallocate()
{
	for(int x = 0; x < dimensions.x.count; ++x)
	{
		for(int y = 0; y < dimensions.y.count; ++y)
		{
			delete [] data[x][y];
		}
		delete [] data[x];
	}
	delete [] data;
}

Dimensions VoxelGrid::getDimensions()
{
	return dimensions;
}

bool *** VoxelGrid::getData()
{
    return data;
}
