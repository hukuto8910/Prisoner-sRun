#pragma once

#include"Collision.h"


class CollisionManager {
public:
	// シングルトン
	static CollisionManager* GetInstance() {
		static CollisionManager s_collision_manager;
		return &s_collision_manager;
	}

	void Update(CollisionObject*o1,CollisionObject*o2) {
		
		CheckHitObject(o1, o2);
		//CheckHitObject(m_collision_list[Collision::CollisionObjectType::PLAYER], m_collision_list[Collision::CollisionObjectType::ENEMY]);
	}

private:
	// 衝突判定のチェック
	void CheckHitObject(CollisionObject* obj1, CollisionObject* obj2) {

		if (obj1 == nullptr || obj2 == nullptr) {
			return;
		}
		// 現在は矩形の判定のみ
		switch (obj1->GetColliderType()) {
		case Collision::ColliderType::RECT:
			CollisionRectAndRect(obj1, obj2);
			break;
		}
	}

	// 矩形と矩形の衝突判定
	void CollisionRectAndRect(CollisionObject* obj1, CollisionObject* obj2) {

		Collision::RectCollider rect1;
		Collision::RectCollider rect2;

		// 衝突形状の所得
		obj1->GetColliderData(rect1);
		obj2->GetColliderData(rect2);

		// 衝突判定
		if (rect1.x < (rect2.x + rect2.wide) && (rect1.x + rect1.wide) > rect2.x &&
			rect1.y < (rect2.y + rect2.heigth) && (rect1.y + rect1.heigth) > rect2.y) {

			// 衝突後の各処理の反映
			obj1->ReflectCollision(obj2);
			obj2->ReflectCollision(obj1);
		}
	}


	std::unordered_map<Collision::CollisionObjectType, CollisionObject*> m_collision_list;
};
