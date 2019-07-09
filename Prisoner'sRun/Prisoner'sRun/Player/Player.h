#pragma once

#include<string>
#include<d3dx9.h>
#include"../LoadResource/LoadResource.h"
#include"../Library/Input/Keyboard.h"


class Player {
public:
	Player() {}
	~Player() {}


	void Init();
	void Update();
	void Draw();

private:
	std::string m_texture;	// 自身の画像
	D3DXVECTOR2 m_pos;		// 位置座標
	float m_speed;			// 移動速度

	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;

	Key& key = Key::GetInstance();
	Resource& res = Resource::GetInstance();
};
