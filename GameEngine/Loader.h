#ifndef _LOADER_H_
#define _LOADER_H_
#include <Windows.h>
class Loader
{
public:
	/// the constructor of the loader
	Loader(void);
	/// the destructor of the loader
	~Loader(void);
	///this method loads a file to a handle 
	HANDLE Load(LPCTSTR filename); 
	private:
	
	/// opens a file that already loaded
	HANDLE openFile(LPCTSTR filename); 
	/// this method delete the loaded file from memory
	void deleteFile(HANDLE currentFile); 	
};
#endif

