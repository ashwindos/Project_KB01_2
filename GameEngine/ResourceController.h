#ifndef __RESOURCECONTROLLER_H_
#define __RESOURCEONTROLLER_H_
#include "Resource.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <map>
#include "Loader.h"
class ResourceController
{
public:

public:

	ResourceController(void);
	~ResourceController(void);
	void OpenFile(std::string);
	void DeleteFile(Resource*);
	void SearchFile(std::string);
	bool isLoaded(std::string);

private:
	Loader *loader;
	//makes a resource
	void makeNewResource(LPCTSTR filename);
	void addToloadedResources(std::string, Resource*);
	void deleteFromLoadedResources(std::string);
	void searchInloadedResources(std::string);
};
#endif

