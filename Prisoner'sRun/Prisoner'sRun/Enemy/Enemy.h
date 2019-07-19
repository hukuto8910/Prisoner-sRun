#pragma once

#include"../Object/CharacterBase.h"


class Enemy :public CharacterBase{
public:
	Enemy() {}
	~Enemy() {}

	void Init();
	void Update();
	void Draw();

	void ReflectCollision(CollisionObject* obj)override {
		m_texture = res.GetTextureName(TextureList::ENEMT_RIGHT_TEX);
		
	}
	Collision::ColliderType GetColliderType()override {
		return m_colliderType;
	}
	Collision::CollisionObjectType GetCollisionObjectData()override {
		return Collision::CollisionObjectType::ENEMY;
	}

	void GetColliderData(Collision::RectCollider& collider)override {
		collider = m_rect_collider;
	}

private:
	Collision::RectCollider m_rect_collider;
	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;
};
