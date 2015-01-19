#ifndef VertexArrayH
#define VertexArrayH

#include "Vertex.h"

/*
This whole thing needs a rewrite. Issues:
1. Initialize might fail when a huge file is specified (there may not be
   a contigous region of memory for a piece of data this big)
2. Init / DeInit / GetElement must have memory / boundary checks and proper
   return codes
3. VertexArray and FaceArray classes should be merged into one class
   (OneDimensionalArray or smth) that would use templates
4. Probably I'm better off just using std::vector instead of all this, though.
*/

class VertexArray
{
public:

	VertexArray(int initSize);
	~VertexArray();

	Vertex * getElement(int index);
	int getCount();

private:

	void initialize(int initSize);
	void deInitialize();

	int count;
	Vertex * data;
};
#endif
