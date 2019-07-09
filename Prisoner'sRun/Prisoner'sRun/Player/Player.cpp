#include"Player.h"
#include"../Library/Draw/Draw.h"


void Player::Init() {
	m_pos = { 0,0 };
	m_speed = 5.f;
	m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_FRONT_TEX);
}

void Player::Update() {
	/*
	移動処理
	斜め移動なし、上下左右
	ダッシュあり、基本歩き
	移動中はアニメーション、停止中は画像を立ち絵に固定
	*/

	// プレイヤーの移動操作
	if (key.On(VK_UP)) {
		m_pos.y -= m_speed;
	}
	else if (key.On(VK_DOWN)) {
		m_pos.y += m_speed;
	}
	else if (key.On(VK_LEFT)) {
		m_pos.x -= m_speed;
	}
	else if (key.On(VK_RIGHT)) {
		m_pos.x += m_speed;
	}
}

void Player::Draw() {
	Draw2D::BoxAnimation(m_texture.c_str(), m_pos, TEXTURE_PARTITION_NUM, 2, 0);
}
