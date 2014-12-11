
#include "DirectX.h"

DirectX::DirectX(void)
{
}

DirectX::DirectX(LPDIRECT3DDEVICE9 nd3ddev, LPDIRECT3D9 nd3dd)
{
	d3dd = nd3dd;
	d3ddev = nd3ddev;
	pMesh = NULL;
	pMeshMaterials = NULL;
	pMeshTextures = NULL;
	dwNumMaterials = 0;
	r = new Logger();	
}

DirectX::~DirectX(void)
{
}

void DirectX::Render()
{
	
    // Clear the backbuffer to a blue color
    d3ddev->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                         D3DCOLOR_XRGB( 0, 0, 255 ), 1.0f, 0 );

    // Begin the scene
    if( SUCCEEDED( d3ddev->BeginScene() ) )
    {
		
	 // Setup the world, view, and projection matrices
        SetupMatrices();

		 for( DWORD i = 0; i < dwNumMaterials; i++ )
        {
            // Set the material and texture for this subset
            d3ddev->SetMaterial( &pMeshMaterials[i] );
            d3ddev->SetTexture( 0, pMeshTextures[i] );

            // Draw the mesh subset
            pMesh->DrawSubset( i );
        }
        // End the scene
        d3ddev->EndScene();
    }

    // Present the backbuffer contents to the display
    d3ddev->Present( NULL, NULL, NULL, NULL );
}


HRESULT DirectX::InitGeometry()
{
 LPD3DXBUFFER pD3DXMtrlBuffer;

    // Load the mesh from the specified file
    if( FAILED( D3DXLoadMeshFromX( L"Tiger.x", D3DXMESH_SYSTEMMEM,
                                   d3ddev, NULL,
                                   &pD3DXMtrlBuffer, NULL, &dwNumMaterials,
                                   &pMesh ) ) )
    {
        // If model is not in current folder, try parent folder
        if( FAILED( D3DXLoadMeshFromX( L"..\\Tiger.x", D3DXMESH_SYSTEMMEM,
                                       d3ddev, NULL,
                                       &pD3DXMtrlBuffer, NULL, &dwNumMaterials,
                                       &pMesh ) ) )
        {
            MessageBox( NULL, L"Could not find boxman.x", L"boxman.x", MB_OK );
            return E_FAIL;
        }
    }

    // We need to extract the material properties and texture names from the 
    // pD3DXMtrlBuffer
    D3DXMATERIAL* d3dxMaterials = ( D3DXMATERIAL* )pD3DXMtrlBuffer->GetBufferPointer();
    pMeshMaterials = new D3DMATERIAL9[dwNumMaterials];
    if( pMeshMaterials == NULL )
        return E_OUTOFMEMORY;
    pMeshTextures = new LPDIRECT3DTEXTURE9[dwNumMaterials];
    if( pMeshTextures == NULL )
        return E_OUTOFMEMORY;

    for( DWORD i = 0; i < dwNumMaterials; i++ )
    {
        // Copy the material
        pMeshMaterials[i] = d3dxMaterials[i].MatD3D;

        // Set the ambient color for the material (D3DX does not do this)
        pMeshMaterials[i].Ambient = pMeshMaterials[i].Diffuse;

        pMeshTextures[i] = NULL;
        if( d3dxMaterials[i].pTextureFilename != NULL &&
            lstrlenA( d3dxMaterials[i].pTextureFilename ) > 0 )
        {
            // Create the texture
            if( FAILED( D3DXCreateTextureFromFileA( d3ddev,
                                                    d3dxMaterials[i].pTextureFilename,
                                                    &pMeshTextures[i] ) ) )
            {
                // If texture is not in current folder, try parent folder
                const CHAR* strPrefix = "..\\";
                CHAR strTexture[MAX_PATH];
                strcpy_s( strTexture, MAX_PATH, strPrefix );
                strcat_s( strTexture, MAX_PATH, d3dxMaterials[i].pTextureFilename );
                // If texture is not in current folder, try parent folder
                if( FAILED( D3DXCreateTextureFromFileA( d3ddev,
                                                        strTexture,
                                                        &pMeshTextures[i] ) ) )
                {
                    MessageBox( NULL, L"Could not find texture map", L"Meshes.exe", MB_OK );
                }
            }
        }
    }

    // Done with the material buffer
    pD3DXMtrlBuffer->Release();

    return S_OK;
}

// this is the function that cleans up Direct3D and COM
void DirectX::cleanD3D()
{
     if( pMeshMaterials != NULL )
        delete[] pMeshMaterials;

    if( pMeshTextures )
    {
        for( DWORD i = 0; i < dwNumMaterials; i++ )
        {
            if( pMeshTextures[i] )
                pMeshTextures[i]->Release();
        }
        delete[] pMeshTextures;
    }

	if( pMesh != NULL )
        pMesh->Release();

    if( d3ddev != NULL )
        d3ddev->Release();

    if( d3dd != NULL )
        d3dd->Release();
}

// this function initializes and prepares Direct3D for use
void DirectX::initD3D(HWND hWnd)
{

    d3dd = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface
	D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


    // create a device class using this information and the info from the d3dpp stuct
    d3dd->CreateDevice(D3DADAPTER_DEFAULT,
                      D3DDEVTYPE_HAL,
                      hWnd,
                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                      &d3dpp,
                      &d3ddev);

	  // Turn on the zbuffer
    d3ddev->SetRenderState( D3DRS_ZENABLE, TRUE );

    // Turn on ambient lighting 
    d3ddev->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	r->Log("Init de window");


};

void DirectX::SetupMatrices()
{
	
    // For our world matrix, we will just rotate the object about the y-axis.
    D3DXMATRIXA16 matWorld;
    D3DXMatrixRotationY( &matWorld, timeGetTime() / 1000.0f );
	d3ddev->SetTransform( D3DTS_WORLD, &matWorld );

   // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, look at the 
    // origin, and define "up" to be in the y-direction.
    D3DXVECTOR3 vEyePt( 0.0f, 3.0f,-5.0f );
    D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
    D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
    d3ddev->SetTransform( D3DTS_VIEW, &matView );

   // For the projection matrix, we set up a perspective transform (which
    // transforms geometry from 3D view space to 2D viewport space, with
    // a perspective divide making objects smaller in the distance). To build
    // a perpsective transform, we need the field of view (1/4 pi is common),
    // the aspect ratio, and the near and far clipping planes (which define at
    // what distances geometry should be no longer be rendered).
    D3DXMATRIXA16 matProj;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f );
    d3ddev->SetTransform( D3DTS_PROJECTION, &matProj );

}



