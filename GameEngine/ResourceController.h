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
class ResourceController
{
public:

	ResourceController(void);
	~ResourceController(void);
	void OpenFile(std::string);
	void DeleteFile(Resource*);
	void SearchFile(std::string);
	bool isLoaded(std::string);

private:
	std::map<std::string, Resource*> _LoadedResources;
	void addToloadedResources(std::string, Resource*);
	void deleteFromLoadedResources(std::string);
	void searchInloadedResources(std::string);
};
#endif

