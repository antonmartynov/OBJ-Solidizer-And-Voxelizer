#include "FileIO.h"
#include "vcl.h"

namespace fileio
{
	void writeFile(UnicodeString filename, UnicodeString content)
	{
		TMemo * memo = new TMemo((HWND)NULL);
		memo->Text = content;
		memo->Lines->SaveToFile(filename);
	}
}
