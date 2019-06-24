#pragma once

#include<d3dx9.h>

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")


namespace Device {

	extern IDirect3DDevice9* dev;

	void Init(HWND hWnd);
	void DrawStart();
	void DrawEnd();
	void Release();
}
