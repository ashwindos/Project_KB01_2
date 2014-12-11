#include "window.h"
#include <windows.h>
#include <string>
#include <d3d9.h>
#include "Renderer.h"
#include "DirectX.h" 

LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam );


Window::Window(HINSTANCE hInstance, int iCmdShow)
{
	r = new Logger();
	Renderer* d = new DirectX();
	init(hInstance, iCmdShow, d);
}



int Window::init( HINSTANCE hInstance,  
                    int iCmdShow,
					Renderer *d)    
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
     
    
	HWND hwnd = CreateWindow( L"Test", L"Test Scherm", WS_OVERLAPPEDWINDOW, 50, 50, 700, 500, NULL, NULL, hInstance, NULL);
  

   
	
    d->initD3D(hwnd);
	 if( SUCCEEDED(d->InitGeometry()))
	 {
    ShowWindow(hwnd, iCmdShow );
    UpdateWindow(hwnd);

     // Enter the message loop
            MSG msg;
            ZeroMemory( &msg, sizeof( msg ) );
    
         while( msg.message != WM_QUIT )
            {
                if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
                {
                    TranslateMessage( &msg );
                    DispatchMessage( &msg );
                }
                else
                    d->Render();
            }
		
	 }
	 UnregisterClass( L"Test", wc.hInstance );
   return 0;
		
	
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