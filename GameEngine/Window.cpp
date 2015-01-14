#include "Window.h"
#include "Logger.h"

LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam );

Window::Window(LPCWSTR windowname, HINSTANCE* hInst)
{
	logger = new Logger();
	name = windowname;
	isUp = true;
	hInstance = hInst;
}

Window::~Window(void)
{
	delete logger;
	delete name;
	delete Instance;
	delete hInstance;
}

int Window::Launch()
{
	// Set up the window class.
	WNDCLASS wc;
    ZeroMemory(&wc, sizeof( wc ));
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0; 
    wc.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH );  
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );     
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );     
    wc.hInstance = *hInstance;      
    wc.lpfnWndProc = WndProc;     
    wc.lpszClassName = TEXT("MainWindow"); 
    wc.lpszMenuName = 0;   
    wc.style = CS_HREDRAW | CS_VREDRAW;
   
    RegisterClass( &wc );
    
	Instance = CreateWindow( L"MainWindow", name, WS_OVERLAPPEDWINDOW, 50, 50, 700, 500, NULL, NULL, *hInstance, NULL);

	ShowWindow(Instance, 5 );
    UpdateWindow(Instance);

	logger->Log("Window creation complete.");
	logger->Log("Entering message loop.");

	// Enter the message loop so the window stays up.
    MSG msg;
    ZeroMemory( &msg, sizeof( msg ) );
    
    while( msg.message != WM_QUIT )
    {
		if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
        {
			TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
	}

	UnregisterClass( L"MainWindow", wc.hInstance );

	isUp = false;
	return 0;
}

bool Window::IsUp()
{
	// TODO implement
	return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam )
{
    switch( message )
    {
		case WM_DESTROY: PostQuitMessage( 0 ); return 0; break;
    }
    return DefWindowProc( hwnd, message, wparam, lparam );
}