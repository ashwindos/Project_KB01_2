#include "SceneController.h"
#include "Scene.h" 
#include <vector>

SceneController::SceneController(void)
{
}

void SceneController::MakeScene()
{
	Scene* s = new Scene();
	Scenes->push_back(s);
}

void SceneController::RefreshAll()
{
	 
}

SceneController::~SceneController(void)
{
}
