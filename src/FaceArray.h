#ifndef FaceArrayH
#define FaceArrayH

#include "Face.h"

/*
Issues related to FaceArray are listed in VertexArray.h, because these
two classes are actually very similar (and this is also an issue in its own
right, and like all the other ones, it's stated there in that file)
*/

class FaceArray
{
public:

	FaceArray(int initSize);
	~FaceArray();

	Face * getElement(int index);
	int getCount();

private:

	void initialize(int initSize);
	void deInitialize();

	int count;
	Face * data;
};

#endif
