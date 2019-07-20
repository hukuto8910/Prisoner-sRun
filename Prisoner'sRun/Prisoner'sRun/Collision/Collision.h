#pragma once

#include"../Object/ObjectBase.h"


// 衝突判定の名前空間
namespace Collision {

	// 矩形の構造体
	struct RectCollider;
	

	// 当たり判定の形状
	enum ColliderType {
		RECT
	};

	// 当たり判定のObject種類
	enum CollisionObjectType {
		PLAYER,
		ENEMY
	};


	// 当たり判定の形状の基底構造体
	struct ColliderBase {

		//ColliderBase() {
		//	x = 0.f;
		//	y = 0.f;
		//}
		//ColliderBase(const ColliderBase& data) {
		//	this->x = data.x;
		//	this->y = data.y;
		//}
		//ColliderBase(float _x, float _y) :x(_x), y(_y) {}

		virtual ColliderType GetColliderType() = 0;


		float x;		// 頂点座標ｘ
		float y;		// 頂点座標ｙ
	};

	// 矩形の構造体
	struct RectCollider :public ColliderBase {

		//RectCollider() :wide(0),heigth(0) {}
		//RectCollider(const RectCollider& data) :ColliderBase(data.x, data.y), wide(data.wide), heigth(data.heigth) {}
		//RectCollider(float _x, float _y, float _wide,float _heigth) :ColliderBase(_x,_y),wide(_wide),heigth(_heigth) {}

		ColliderType GetColliderType()override {
			return ColliderType::RECT;
		}


		float wide;		// 矩形の横幅
		float heigth;	// 矩形の縦幅
	};
}


// 衝突判定の抽象クラス
class CollisionObject :public ObjectBase {
public:
	CollisionObject() {}
	~CollisionObject()override {}


	// 衝突していた場合の処理
	virtual void ReflectCollision(CollisionObject* obj) = 0;

	// 衝突判定の形状のゲッター
	virtual Collision::ColliderType GetColliderType() = 0;

	// 衝突判定を持つオブジェクトの種類
	virtual Collision::CollisionObjectType GetCollisionObjectType() = 0;

	// 衝突判定に使用する形状の情報ゲッター
	virtual void GetColliderData(Collision::RectCollider& collider) {}

protected:
};
