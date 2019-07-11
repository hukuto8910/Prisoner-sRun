#pragma once

#include"../Object/CharacterBase.h"


class Enemy :public CharacterBase{
public:
	Enemy() {}
	~Enemy() {}

	void Init();
	void Update();
	void Draw();

private:
	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;
};
