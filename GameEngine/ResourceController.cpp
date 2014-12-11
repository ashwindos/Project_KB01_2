#include "ResourceController.h"

ResourceController::ResourceController(void)
{
}


ResourceController::~ResourceController(void)
{
}

void ResourceController::OpenFile()
{
	//implementatie
	std::ofstream outfile;
	outfile.open("C:/Users/Ashwin/Desktop/Project_KB01_2/Resource/Textures/banana.bmp", std::ios_base::app);
	
}
void ResourceController::CloseFile()
{
	//implementatie
}
void ResourceController::DeleteFile(Resource)
{
	//implementatie
}
void ResourceController::SearchFile()
{
	//implementatie
}

