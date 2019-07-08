#pragma once

#include<string>


class Player {
public:
	Player() {}
	~Player() {}


	void Init();
	void Update();
	void Draw();

private:
	std::string m_texture;	// 自身の画像
};
