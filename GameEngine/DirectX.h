#ifndef __DIRECTX_H_
#define __DIRECTX_H_
#include <windows.h>
#include <windowsx.h>
#include "Logger.h"
#include "Entity.h"
#include <d3dx9.h>
#include <mmsystem.h>
#include "Renderer.h"
#include <strsafe.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "winmm.lib")



class DirectX : public Renderer
{
private:
LPDIRECT3D9 d3dd;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
LPD3DXMESH          pMesh; // Our mesh object in sysmem
D3DMATERIAL9*       pMeshMaterials; // Materials for our mesh
LPDIRECT3DTEXTURE9* pMeshTextures; // Textures for our mesh
DWORD               dwNumMaterials;   // Number of mesh materials
Logger*				r; // Logger

public:
	DirectX(void);
	DirectX(LPDIRECT3DDEVICE9, LPDIRECT3D9); // constructor
	~DirectX(void);

	// function prototypes
void initD3D(HWND hwnd);    // sets up and initializes Direct3D
void SetupMatrices();
void Render();    // renders a single frame
HRESULT InitGeometry();
void cleanD3D();    // closes Direct3D and releases memory
};
#endif
