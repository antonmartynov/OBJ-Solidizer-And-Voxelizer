#include "VertexArray.h"

VertexArray::VertexArray(int initSize)
{
	initialize(initSize);
}

VertexArray::~VertexArray()
{
	deInitialize();
}

void VertexArray::initialize(int initSize)
{
	data = new Vertex [initSize];
	count = initSize;
}

void VertexArray::deInitialize()
{
	delete [] data;
}

Vertex * VertexArray::getElement(int index)
{
	return &(data[index]);
}

int VertexArray::getCount()
{
    return count;
}
