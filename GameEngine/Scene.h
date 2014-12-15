#ifndef __SCENE_H_
#define __SCENE_H_
class Scene
{
public:
	Scene(void);
	~Scene(void);

	/// Calls Draw() for each entity in the scene.
	void Refresh();
};
#endif

