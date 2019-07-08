#include"Player.h"
#include"../Library/Draw/Draw.h"


void Player::Init() {
	m_pos = { 0,0 };
	m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_FRONT_TEX);
}

void Player::Update() {
	/*
	移動処理
	斜め移動なし、上下左右
	ダッシュあり、基本歩き
	移動中はアニメーション、停止中は画像を立ち絵に固定
	*/
}

void Player::Draw() {
	Draw2D::Box(m_texture.c_str(), m_pos);
}
