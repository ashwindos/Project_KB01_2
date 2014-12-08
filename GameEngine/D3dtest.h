#include <d3d9.h>
#pragma once


class D3dtest
{
private:
	// global declarations
LPDIRECT3D9 d3dd;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class

public:
D3dtest();
D3dtest(LPDIRECT3DDEVICE9, LPDIRECT3D9); // constructor
~D3dtest();

// function prototypes
void initD3D(HWND hwnd);    // sets up and initializes Direct3D
void render_frame(void);    // renders a single frame
void cleanD3D(void);    // closes Direct3D and releases memory
};