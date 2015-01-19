#include "FaceArray.h"

FaceArray::FaceArray(int initSize)
{
	initialize(initSize);
}

FaceArray::~FaceArray()
{
	deInitialize();
}

void FaceArray::initialize(int initSize)
{
	data = new Face [initSize];
	count = initSize;
}

void FaceArray::deInitialize()
{
	delete [] data;
}

Face * FaceArray::getElement(int index)
{
	return &(data[index]);
}

int FaceArray::getCount()
{
	return count;
}
