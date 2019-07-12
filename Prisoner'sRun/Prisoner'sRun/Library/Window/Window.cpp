#include"Window.h"


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

namespace Window {

	// ウィンドウ生成
	HWND MakeWindow(int width, int height) {

		// インスタンスハンドルの取得
		HINSTANCE h_instance = GetModuleHandle(nullptr);

		// ウィンドウクラス作成
		WNDCLASSEX wc = {
			sizeof(WNDCLASSEX),					// 構造体サイズ
			CS_HREDRAW | CS_VREDRAW,			// ウィンドウスタイル
			WindowProc,							// プロシージャ
			0,									// 予備メモリ
			0,									// 作成時に作られるメモリ
			h_instance,							// インスタンスハンドル
			LoadIcon(nullptr,IDI_APPLICATION),	// ショートカットアイコン
			LoadCursor(nullptr,IDC_ARROW),		// マウスカーソル
			nullptr,							// クライアント領域の背景色
			nullptr,							// メニュー名
			TEXT("ウィンドウ"),					// ウィンドウクラス名
			nullptr								// タイトルバーアイコン
		};

		if (RegisterClassEx(&wc) == 0) {
			MessageBox(0, "ウィンドウクラスの登録に失敗しました。", nullptr, MB_OK);
			return 0;
		}

		// ウィンドウ作成
		HWND h_wnd = CreateWindow(
			TEXT("ウィンドウ"),					// ウィンドウクラス名
			TEXT("default"),					// ウィンドウ名
			WS_OVERLAPPEDWINDOW,/*WS_POPUP,*/	// ウィンドウスタイル
			CW_USEDEFAULT,						// X初期位置
			CW_USEDEFAULT,						// Y初期位置
			width,								// 横幅
			height,								// 縦幅
			nullptr,							// 親ウィンドウ
			nullptr,							// メニューハンドル
			h_instance,							// インスタンスハンドル
			nullptr								// CREATESTRUCTの構造体ポインタ
		);

		if (h_wnd == nullptr) {

			MessageBox(0, "ウィンドウクラスの作成に失敗", nullptr, MB_OK);
			return 0;
		}

		// ウィンドウの表示
		ShowWindow(h_wnd, SW_SHOW);

		return h_wnd;
	}


	bool ProcessMessage() {

		MSG msg;

		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) {
				return false;
			}
		}
		return true;
	}
}
