#pragma once

#include<windows.h>


const int WINDOW_W = 1920;
const int WINDOW_H = 1080;

namespace Window {

	// ウィンドウの生成
	HWND MakeWindow(int width, int height);

	bool ProcessMessage();
}
