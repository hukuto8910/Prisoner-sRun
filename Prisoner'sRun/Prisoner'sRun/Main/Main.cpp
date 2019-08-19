#include <crtdbg.h>
#include"../Library/Device/Device.h"
#include"../Library/Window/Window.h"
#include"../Library/Input/Keyboard.h"
#include"../Library/Texture/Texture.h"
#include"../Library/Draw/Draw.h"
#include"../LoadResource/LoadResource.h"
#include"../Scene/SceneManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	HWND h_wnd = Window::MakeWindow(WINDOW_W, WINDOW_H);
	Device::Init(h_wnd);
	
	LPDIRECT3DDEVICE9 dev = Device::dev;
	// 透過処理　以下調べて別途で改めて記述すること
	//dev->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	dev->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	//dev->SetRenderState(D3DRS_ALPHAREF, 0x0000000);
	dev->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	Key& key = Key::GetInstance();
	Resource& res = Resource::GetInstance();
	SceneManager& scene_manager = SceneManager::GetInstance();
	
	scene_manager.Init();
	res.Load();
	Texture tex;

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
	tex.Relese();
	Device::Release();
	return 0;
}
