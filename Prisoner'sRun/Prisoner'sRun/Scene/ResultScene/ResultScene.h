#pragma once

#include"../SceneBase.h"


class Result :public SceneBase{
public:
	Result();
	~Result()override {}

	void Init()override;
	void Update()override;
	void Draw()override;

private:
	std::string m_texture;	// リザルト画面の画像
};
