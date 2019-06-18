#include"Device.h"


namespace Device {

	LPDIRECT3D9 direct3d9 = nullptr;	// IDirect3D9
	LPDIRECT3DDEVICE9 dev = nullptr;	// IDirect3DDevice9

	void Init(HWND hWnd) {

		direct3d9 = Direct3DCreate9(D3D_SDK_VERSION);

		if (direct3d9 == nullptr) {

			MessageBox(0, "Dirext3D9インターフェースの取得に失敗しました。", nullptr, MB_OK);
			return;
		}

		D3DPRESENT_PARAMETERS pp = {
			0,							// バックバッファ横幅
			0,							// バックバッファ縦幅
			D3DFMT_A8R8G8B8,			// バックバッファの画面フォーマット情報
			1,							// バックバッファの数
			D3DMULTISAMPLE_4_SAMPLES,	// マルチサンプルの数
			0,							// マルチサンプルの品質レベル
			D3DSWAPEFFECT_DISCARD,		// バッファの切り替え方法
			hWnd,						// ウィンドウハンドル
			TRUE,						// スクリーンモード
			TRUE,						// 深度ステンシルバッファの有無
			D3DFMT_D24S8,				// ステンシルバッファのフォーマット
			D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL,// バッファ転送時オプション
			0,							// フルスクリーンでのリフレッシュレート
			D3DPRESENT_INTERVAL_ONE		// スワップエフェクトの書き換えタイミング
		};

		direct3d9->CreateDevice(
			D3DADAPTER_DEFAULT,			// ディスプレイアダプタの種類
			D3DDEVTYPE_HAL,				// デバイスの種類
			hWnd,						// ウィンドウハンドル
			D3DCREATE_HARDWARE_VERTEXPROCESSING,// デバイス制御
			&pp,						// D3DPRESENT_PARAMETRERS
			&dev						// IDirect3DDevice9のポインタアドレス
		);
	}

	void DrawStart() {
		dev->Clear(
			0, nullptr,
			D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
			NULL,
			1.0f, 0
		);

		dev->BeginScene();
	}

	void DrawEnd() {
		dev->EndScene();
		dev->Present(nullptr, nullptr, nullptr, nullptr);
	}

	void Release() {
		if (dev != nullptr) {
			dev->Release();
		}
		if (direct3d9 != nullptr) {
			direct3d9->Release();
		}
	}
}