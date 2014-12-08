#include "Entity.h"

#ifndef RENDERER_H
#define RENDERER_H
class Renderer
{
public:
	virtual ~Renderer(void);
	virtual void Render(Entity);
};
#endif