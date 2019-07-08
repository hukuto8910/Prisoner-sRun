#pragma once

#include<string>
#include"../SceneBase.h"


class Title :public SceneBase{
public:
	Title();
	~Title()override {};

	void Init()override;
	void Update()override;
	void Draw()override;

private:
	std::string m_texture;	// タイトル画面の画像
};
