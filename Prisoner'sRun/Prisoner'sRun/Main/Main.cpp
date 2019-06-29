#include<d3dx9.h>
#include"../Library/Device/Device.h"
#include"../Library/Window/Window.h"
#include"../Library/Input/Keyboard.h"
#include"../Library/Texture/Texture.h"
#include"../Library/Draw/Draw.h"
#include"../Map/Map.h"
#include"../LoadResource.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
	
	HWND h_wnd = Window::MakeWindow(WINDOW_W, WINDOW_H);
	Device::Init(h_wnd);
	LPDIRECT3DDEVICE9 dev = Device::dev;
	Key& key = Key::GetInstance();
	//Texture test = "Resource/Object/close_locker.png";
	
	Resource::Load();
	Map map;

	while (Window::ProcessMessage()) {
		
		key.Update();
		if (key.Press(VK_ESCAPE)) {
			break;
		}

		Device::DrawStart();

		// テスト用の描画
		//Draw2D::Box(test, { 100,200 },1,1,0,0,0,0x00ffffff);
		map.Draw();

		Device::DrawEnd();
	}

	Resource::Relese();
	Device::Release();
	return 0;
}
