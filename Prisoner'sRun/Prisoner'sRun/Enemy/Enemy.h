#pragma once

#include<string>
#include<d3dx9.h>
#include"../LoadResource/LoadResource.h"


class Enemy {
public:
	Enemy() {}
	~Enemy() {}

	void Init();

	void Update();

	void Draw();

private:
	std::string m_texture;
	D3DXVECTOR2 m_pos;
	int m_speed;

	Resource& res = Resource::GetInstance();
};
