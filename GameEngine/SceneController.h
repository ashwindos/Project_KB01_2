#ifndef __SCENECONTROLLER_H_
#define __SCENECONTROLLER_H_

#include "Scene.h"
#include <vector>
#include "Scene.h"

class SceneController
{
public:
	SceneController(void);
	~SceneController(void);
	void MakeScene(void);
	void RefreshAll(void);
private:
	std::vector<Scene*>* Scenes;
};
#endif
