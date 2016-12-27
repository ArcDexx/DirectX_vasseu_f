#include "stdafx.h"
#include "3DTP.h"
#include "InputManager.h"

// Global Variables:
HINSTANCE hInst;			// current instance
HWND			hWnd;				// windows handle used in DirectX initialization
IAEngine::InputManager* g_pInputManager = NULL;


// Forward declarations
bool				CreateWindows(HINSTANCE, int, HWND& hWnd);
bool				CreateDevice();
void RenderFrame(void);     // renders a single frame


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG oMsg;
	ulong	iElaspedTime = 0;
	ulong	iLastTime = 0;

	hInst = hInstance;
	if (!CreateWindows (hInstance, nCmdShow, hWnd))
	{
		MessageBox(NULL, L"Erreur lors de la création de la fenêtre", L"Error", 0);
		return false;
	}
	g_pInputManager = new IAEngine::InputManager();
	if (!g_pInputManager->Create(hInst, hWnd))
	{
		MessageBox(NULL, L"Erreur lors de la création de l'input manager", L"Error", 0);
		delete g_pInputManager;
		return false;
	}
	if (!CreateDevice())
	{
		MessageBox(NULL, L"Erreur lors de la création du device DirectX 11", L"Error", 0);
		return false;
	}

	//Create and fill other DirectX Stuffs like Vertex/Index buffer, shaders 

	iLastTime = timeGetTime();
	PeekMessage( &oMsg, NULL, 0, 0, PM_NOREMOVE );
	while ( oMsg.message != WM_QUIT )
	{
		if (PeekMessage( &oMsg, NULL, 0, 0, PM_REMOVE )) 
		{
			TranslateMessage( &oMsg );
			DispatchMessage( &oMsg );
		}
		else
		{
			ulong iTime = timeGetTime();
			iElaspedTime = iTime - iLastTime;
			iLastTime = iTime;
			float fElaspedTime = iElaspedTime * 0.001f;

			g_pInputManager->Manage();
			// Do a lot of thing like draw triangles with DirectX
			RenderFrame();
		}
	}
	//Release D3D objectssss
	delete g_pInputManager;
	return (int) oMsg.wParam;
}

// this is the function used to render a single frame
void RenderFrame(void)
{
	float color[4] = { 0.0f, 0.2f, 0.4f, 1.0f };
	// clear the back buffer to a deep blue
	devcon->ClearRenderTargetView(backbuffer, color);

	// do 3D rendering on the back buffer here

	// switch the back buffer and the front buffer
	swapchain->Present(0, 0);
}

bool CreateDevice()
{
	return true;
}
