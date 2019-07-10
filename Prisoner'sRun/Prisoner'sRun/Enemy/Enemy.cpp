#include"Enemy.h"
#include"../Library/Draw/Draw.h"


void Enemy::Init() {
	m_pos = { 100,0 };
	m_speed = 3;
	m_texture = res.GetTextureName(TextureList::ENEMY_FRONT_TEX);
}

void Enemy::Update() {

}

void Enemy::Draw() {
	Draw2D::BoxAnimation(m_texture.c_str(), m_pos, 4, 1, 0);
}
