#pragma once

#include"../Object/CharacterBase.h"
#include"../Library/Input/Keyboard.h"


// プレイヤークラス
class Player :public CharacterBase{
public:
	Player() {}
	~Player() {}


	void Init()override;
	void Update()override;
	void Draw()override;

	// 衝突後の処理
	void ReflectCollision(CollisionObject* obj)override {}
	
	// 衝突形状のゲッター
	Collision::ColliderType GetColliderType()override {
		return m_rect_collider.GetColliderType();
	}

	// 衝突オブジェクトの種類ゲッター
	Collision::CollisionObjectType GetCollisionObjectType()override {
		return Collision::CollisionObjectType::PLAYER;
	}

	// 衝突形状の情報ゲッター
	void GetColliderData(Collision::RectCollider& collider)override {
		collider = m_rect_collider;
	}

private:
	Collision::RectCollider m_rect_collider;	// 衝突形状  矩形

	// 画像の分割数
	const int TEXTURE_PARTITION_NUM = 4;

	Key& key = Key::GetInstance();	// 移動用のキーボード変数
};
