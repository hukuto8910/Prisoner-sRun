#pragma once

#include"../Object/CharacterBase.h"
#include"../Library/Input/Keyboard.h"


class Player :public CharacterBase{
public:
	Player() {}
	~Player() {}


	void Init()override;
	void Update()override;
	void Draw()override;

	void ReflectCollision(CollisionObject* obj)override {}
	Collision::ColliderType GetColliderType()override {
		return m_colliderType;
	}
	Collision::CollisionObjectType GetCollisionObjectData()override {
		return Collision::CollisionObjectType::PLAYER;
	}

	void GetColliderData(Collision::RectCollider& collider)override {
		collider = m_rect_collider;
	}

private:
	Collision::RectCollider m_rect_collider;
	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;

	Key& key = Key::GetInstance();	// 移動用のキーボード変数
};
