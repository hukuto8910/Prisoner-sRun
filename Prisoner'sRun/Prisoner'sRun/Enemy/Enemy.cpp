#include"Enemy.h"


void Enemy::Init() {

	m_pos = { 100,0 };
	m_speed = 3.f;

	m_animation_tex_num = 4;
	m_animation_num = 0;
	m_animation_speed = 10;
	m_texture = res.GetTextureName(TextureList::ENEMY_FRONT_TEX);

	m_rect_collider.x = m_pos.x;
	m_rect_collider.y = m_pos.y;
	m_rect_collider.heigth = 128;
	m_rect_collider.wide = 64;
	m_colliderType = Collision::ColliderType::RECT;
}

void Enemy::Update() {
	m_rect_collider.x = m_pos.x;
	m_rect_collider.y = m_pos.y;
}

void Enemy::Draw() {

	Draw2D::BoxAnimation(m_texture.c_str(), m_pos, TEXTURE_PARTITION_NUM, 1, m_animation_num);
	// アニメーションの更新
	AnimationCount(m_animation_speed);
}
