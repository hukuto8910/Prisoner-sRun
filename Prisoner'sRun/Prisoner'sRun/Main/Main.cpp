﻿#include<d3dx9.h>
#include"../Library/Device/Device.h"
#include"../Library/Window/Window.h"
#include"../Library/Input/Keyboard.h"
#include"../Library/Texture/Texture.h"
#include"../Library/Draw/Draw.h"
#include"../LoadResource/LoadResource.h"
#include"../Scene/SceneManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
	
	HWND h_wnd = Window::MakeWindow(WINDOW_W, WINDOW_H);
	Device::Init(h_wnd);
	
	LPDIRECT3DDEVICE9 dev = Device::dev;

	Key& key = Key::GetInstance();
	Resource& res = Resource::GetInstance();
	SceneManager& scene_manager = SceneManager::GetInstance();
	
	scene_manager.Init();
	res.Load();

	while (Window::ProcessMessage()) {
		
		key.Update();

		if (key.Press(VK_ESCAPE)) {
			break;
		}
		
		scene_manager.Update();

		if (scene_manager.IsQuit() == true) {
			break;
		}

		Device::DrawStart();

		scene_manager.Draw();

		Device::DrawEnd();
	}

	res.Relese();
	Device::Release();
	return 0;
}
