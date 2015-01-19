#ifndef FileIOH
#define FileIOH

#include <vcl.h>

/*

File input / output operations are generally platform dependent,
so I've moved everything related to them into a separate file
(and separate namespace).

*/

namespace fileio
{
	void writeFile(UnicodeString filename, UnicodeString content);
}

#endif
