#include"Keyboard.h"


Key& Key::GetInstance() {
	static Key key;
	return key;
}

bool Key::Test(BYTE key)const {
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

bool Key::On(int nVirKey) {
	return Test(keys[0][nVirKey]);
}

bool Key::Press(int nVirKey) {
	return Test(keys[0][nVirKey]) && !Test(keys[1][nVirKey]);
}

bool Key::Release(int nVirKey) {
	return !Test(keys[0][nVirKey]) && Test(keys[1][nVirKey]);
}
