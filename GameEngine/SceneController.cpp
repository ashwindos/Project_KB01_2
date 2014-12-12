#include "SceneController.h"
#include "Scene.h"
#include <vector>

SceneController::SceneController(void)
{
	Scenes = new std::vector<Scene*>();
}

void SceneController::MakeScene()
{
	Scene* s = new Scene();
	Scenes->push_back(s);
}

void SceneController::RefreshAll()
{
	std::vector<Scene*>::iterator it;
	for (it = Scenes->begin() ; it != Scenes->end(); ++it)
	{
		(*it)->Refresh();
	}
}

SceneController::~SceneController(void)
{
	Scenes->clear();
	delete Scenes;
}
