#include "ResourceController.h"

ResourceController::ResourceController(void)
{	loader = new Loader();
	
}


ResourceController::~ResourceController(void)
{
}

void ResourceController::OpenFile(std::string path)
{
	//implementatie
	std::ofstream outfile;
	outfile.open(path, std::ios_base::app);
	
}
void ResourceController::DeleteFile(Resource*)
{
	//implementatie
}
void ResourceController::SearchFile(std::string)
{
	//implementatie
}
void ResourceController :: makeNewResource(LPCTSTR filename)
{
	HANDLE handle =
	loader->Load(filename);
}


