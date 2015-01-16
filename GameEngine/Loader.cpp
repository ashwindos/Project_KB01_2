#include "Loader.h"


Loader::Loader(void)
{
}


Loader::~Loader(void)
{
}


HANDLE Loader ::Load(LPCTSTR filename)
{
	HANDLE handle = 
		LoadImage(NULL,filename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		return handle;
}

HANDLE Loader ::openFile(LPCTSTR filename)
{
	HANDLE handle = 
		LoadImage(NULL,filename,IMAGE_BITMAP,0,0,LR_SHARED);
		return handle;
}

void Loader ::deleteFile(HANDLE currentFile)
{
		DeleteObject(currentFile);
}

