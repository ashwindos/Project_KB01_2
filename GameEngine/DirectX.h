#ifndef __DIRECTX_H_
#define __DIRECTX_H_
#include <d3d9.h>
#include "Renderer.h" 


class DirectX : public Renderer
{
private:
	// global declarations
LPDIRECT3D9 d3dd;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class

public:
	DirectX(void);
	DirectX(LPDIRECT3DDEVICE9, LPDIRECT3D9); // constructor
	~DirectX(void);

	// function prototypes
void initD3D(HWND hwnd);    // sets up and initializes Direct3D
void Render();    // renders a single frame
void cleanD3D();    // closes Direct3D and releases memory
};
#endif
