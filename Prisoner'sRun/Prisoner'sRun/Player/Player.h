#pragma once

#include"../Object/CharacterBase.h"
#include"../Library/Input/Keyboard.h"


class Player :public CharacterBase{
public:
	Player() {}
	~Player() {}


	void Init();
	void Update();
	void Draw();

private:
	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;

	Key& key = Key::GetInstance();	// 移動用のキーボード変数
};
