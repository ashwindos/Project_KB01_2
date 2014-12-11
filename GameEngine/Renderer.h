#ifndef __RENDERER_H_
#define __RENDERER_H_
#include "Entity.h"
#include <Windows.h>


class Renderer
{
public:


	Renderer(){}
	virtual ~Renderer(){}
	virtual void Render()= 0;;
	virtual void initD3D(HWND)= 0; 
	virtual void cleanD3D(void)= 0;
	virtual HRESULT InitGeometry()= 0;
};
#endif