// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma warning(push)
#pragma warning(disable : 4005)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP
#define NOMCX
#define NOSERVICE
#define NOHELP
#pragma warning(pop)

// Windows Header Files:
#include <windows.h>
#include <mmsystem.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdint.h>
#include <utility>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <vector>


#include <d3d11.h>
#include <dinput.h>

#include "Defines.h"
#include "Types.h"
#include "DirectXTK/SimpleMath.h"


ID3D11RenderTargetView *backbuffer;    // the pointer to our back buffer
IDXGISwapChain *swapchain;             // the pointer to the swap chain interface
ID3D11Device *dev;                     // the pointer to our Direct3D device interface
ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context