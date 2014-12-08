// include the basic windows header files and the Direct3D header file
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include "D3dtest.h"
// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")

D3dtest::D3dtest()
{
}
D3dtest::D3dtest(LPDIRECT3DDEVICE9 nd3ddev, LPDIRECT3D9 nd3dd)
{
	d3dd = nd3dd;
	d3ddev = nd3ddev;
}

D3dtest::~D3dtest()
{
}


// this is the function used to render a single frame
void D3dtest::render_frame(void)
{
    // clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(5, 200, 20), 1.0f, 0);

    d3ddev->BeginScene();    // begins the 3D scene

    // do 3D rendering on the back buffer here

    d3ddev->EndScene();    // ends the 3D scene

    d3ddev->Present(NULL, NULL, NULL, NULL);    // displays the created frame
}

// this is the function that cleans up Direct3D and COM
void D3dtest::cleanD3D(void)
{
    d3ddev->Release();    // close and release the 3D device
    d3dd->Release();    // close and release Direct3D
}

// this function initializes and prepares Direct3D for use
void D3dtest::initD3D(HWND hWnd)
{
    d3dd = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

    D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

    ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
    d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
    d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D


    // create a device class using this information and the info from the d3dpp stuct
    d3dd->CreateDevice(D3DADAPTER_DEFAULT,
                      D3DDEVTYPE_HAL,
                      hWnd,
                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                      &d3dpp,
                      &d3ddev);
}