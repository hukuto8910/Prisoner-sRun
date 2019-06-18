#include<d3dx9.h>
#include"Device.h"
#include"Window.h"
#include"Keyboard.h"
#include"Texture.h"
#include"Draw.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
	
	HWND h_wnd = Window::MakeWindow(WINDOW_W, WINDOW_H);
	Device::Init(h_wnd);
	LPDIRECT3DDEVICE9 dev = Device::dev;
	Key& key = Key::GetInstance();
	Texture test = "hora_attack.png";

	while (Window::ProcessMessage()) {
		
		key.Update();
		if (key.Press(VK_ESCAPE)) {
			break;
		}

		Device::DrawStart();

		// テスト用の描画
		//Draw2D::Box(test, { 100,200 },1,1,0,0,0,0x00ffffff);

		Device::DrawEnd();
	}
	Device::Release();
	return 0;
}
