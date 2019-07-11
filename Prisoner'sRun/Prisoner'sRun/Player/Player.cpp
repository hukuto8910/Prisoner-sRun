#include"Player.h"


void Player::Init() {

	m_pos = { 0,0 };
	m_speed = 5.f;

	m_animation_tex_num = 4;
	m_animation_num = 0;
	m_animation_speed = 10;
	m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_FRONT_TEX);
}

void Player::Update() {
	/*
	・移動処理を関数化　CheckMoveKye
	・アイテム処理が入ったら画像が変わるので、それ用の変数をつくる
	　　// 警棒時
		m_front_texture = ...TextureList::PLAYER_BATON_FRONT_TEX;
		// 通常時
		m_front_texture = ...TextureList::PLAYER_NORMAL_FRONT_TEX;
		// 操作中の画像代入
		m_texture = m_front_texture;
	*/

	// プレイヤーの移動操作
	if (key.On(VK_UP)) {

		m_pos.y -= m_speed;
		m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_BACK_TEX);
		AnimationCount(m_animation_speed);
	}
	else if (key.On(VK_DOWN)) {

		m_pos.y += m_speed;
		m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_FRONT_TEX);
		AnimationCount(m_animation_speed);
	}
	else if (key.On(VK_LEFT)) {

		m_pos.x -= m_speed;
		m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_LEFT_TEX);
		AnimationCount(m_animation_speed);
	}
	else if (key.On(VK_RIGHT)) {

		m_pos.x += m_speed;
		m_texture = res.GetTextureName(TextureList::PLAYER_NORMAL_RIGHT_TEX);
		AnimationCount(m_animation_speed);
	}
	// 移動していないときは直立の画像に戻す
	else {
		m_animation_num = 0;
	}
}

void Player::Draw() {
	Draw2D::BoxAnimation(m_texture.c_str(), m_pos, TEXTURE_PARTITION_NUM, 1, m_animation_num);
}
