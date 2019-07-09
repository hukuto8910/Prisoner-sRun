#pragma once

#include"ObjectBase.h"


class CharacterBase :public ObjectBase {
public:
	CharacterBase() {}
	virtual ~CharacterBase() {}

	/*
	・アニメーション回す関数
	・死亡判定
	*/

protected:
	int m_speed;	// 移動速度
};
