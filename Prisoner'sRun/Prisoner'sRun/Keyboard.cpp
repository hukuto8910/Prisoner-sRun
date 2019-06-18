#include"Keyboard.h"


Key& Key::GetInstance() {
	static Key key;
	return key;
}

bool Key::Test(BYTE key) {
	return ((key & 0x80) != 0);
}

void Key::Update() {
	memcpy(keys[1], keys[0], sizeof(*keys));
	// 全てのkeyの状態を取得
	GetKeyboardState(keys[0]);
}

//void Key::Reset() {
//	memset(keys, 0, sizeof(keys));
//}

bool Key::On(int n_vir_key) {
	return Test(keys[0][n_vir_key]);
}

bool Key::Press(int n_vir_key) {
	return Test(keys[0][n_vir_key]) && !Test(keys[1][n_vir_key]);
}

bool Key::Release(int n_vir_key) {
	return !Test(keys[0][n_vir_key]) && Test(keys[1][n_vir_key]);
}
