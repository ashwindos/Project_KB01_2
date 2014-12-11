#include "SceneController.h"
#include "Scene.h" 
#include <vector>

SceneController::SceneController(void)
{
}

void SceneController::MakeScene()
{
	Scenes->push_back(new Scene());
}

void SceneController::RefreshAll()
{
	 
}

SceneController::~SceneController(void)
{
}
