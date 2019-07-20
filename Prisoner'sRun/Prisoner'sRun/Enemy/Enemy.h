#pragma once

#include"../Object/CharacterBase.h"


// エネミークラス
class Enemy :public CharacterBase{
public:
	Enemy() {}
	~Enemy() {}

	void Init();
	void Update();
	void Draw();

	// 衝突後の処理
	void ReflectCollision(CollisionObject* obj)override {
		m_texture = res.GetTextureName(TextureList::ENEMT_RIGHT_TEX);
	}

	// 衝突形状のゲッター
	Collision::ColliderType GetColliderType()override {
		return m_rect_collider.GetColliderType();
	}

	// 衝突オブジェクトの種類ゲッター
	Collision::CollisionObjectType GetCollisionObjectType()override {
		return Collision::CollisionObjectType::ENEMY;
	}

	// 衝突形状の情報ゲッター
	void GetColliderData(Collision::RectCollider& collider)override {
		collider = m_rect_collider;
	}

private:
	Collision::RectCollider m_rect_collider;	// 衝突形状　矩形

	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;
};
