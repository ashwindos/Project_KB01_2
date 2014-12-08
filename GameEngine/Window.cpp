#include "window.h"
#include <windows.h>
#include <string>
#include <d3d9.h>
#include "D3dtest.h"

LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam );


Window::Window(HINSTANCE hInstance, int iCmdShow)
{
	
	D3dtest* d = new D3dtest();
	init(hInstance, iCmdShow, d);
}



int Window::init( HINSTANCE hInstance,  
                    int iCmdShow,
					D3dtest *d)    
{
   
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof( wc ));
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0; 
    wc.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH );  
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );     
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );     
    wc.hInstance = hInstance;      
    wc.lpfnWndProc = WndProc;     
    wc.lpszClassName = TEXT("Test"); 
    wc.lpszMenuName = 0;   
    wc.style = CS_HREDRAW | CS_VREDRAW;
   
    RegisterClass( &wc );
     
    
	HWND hwnd = CreateWindow(TEXT ("Test"), TEXT("Test Scherm"), WS_OVERLAPPEDWINDOW, 50, 50, 700, 500, NULL, NULL, hInstance, NULL);
  

    ShowWindow(hwnd, iCmdShow );
	 d->initD3D(hwnd);
    UpdateWindow(hwnd);
   
 
    
 
    MSG msg;
    
    while( GetMessage( &msg, NULL, 0, 0 ) )
    {
        
        TranslateMessage( &msg );
       
        DispatchMessage( &msg );   
	d->render_frame();
        
    }
	d->cleanD3D();
   return msg.wParam; 
}
 
LRESULT CALLBACK WndProc(   HWND hwnd,
                            UINT message,
                            WPARAM wparam,
                            LPARAM lparam )
{
    
 
    switch( message )
    {
    case WM_DESTROY:
        PostQuitMessage( 0 ) ;
        return 0;
        break;
         
    }
 
    
    return DefWindowProc( hwnd, message, wparam, lparam );
}