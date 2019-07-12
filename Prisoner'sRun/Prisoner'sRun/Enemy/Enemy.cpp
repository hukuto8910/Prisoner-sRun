#include"Enemy.h"


void Enemy::Init() {

	m_pos = { 100,0 };
	m_speed = 3.f;

	m_animation_tex_num = 4;
	m_animation_num = 0;
	m_animation_speed = 10;
	m_texture = res.GetTextureName(TextureList::ENEMY_FRONT_TEX);
}

void Enemy::Update() {

}

void Enemy::Draw() {

	Draw2D::BoxAnimation(m_texture.c_str(), m_pos, TEXTURE_PARTITION_NUM, 1, m_animation_num);
	// アニメーションの更新
	AnimationCount(m_animation_speed);
}
