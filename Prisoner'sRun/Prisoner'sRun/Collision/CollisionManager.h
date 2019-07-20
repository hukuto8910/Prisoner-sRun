#pragma once

#include"Collision.h"


// 衝突判定管理クラス
class CollisionManager {
public:
	// シングルトン
	static CollisionManager* GetInstance() {
		static CollisionManager s_collision_manager;
		return &s_collision_manager;
	}

	void Update();

	// 衝突オブジェクトリスト登録関数
	void Entry(CollisionObject* obj) {
		m_collision_list.emplace(obj->GetCollisionObjectType(), obj);
	}

private:
	// 衝突判定のチェック
	void CheckHitObject(CollisionObject* obj1, CollisionObject* obj2);

	// 矩形と矩形の衝突判定
	void CollisionRectAndRect(CollisionObject* obj1, CollisionObject* obj2);

private:
	std::unordered_map<Collision::CollisionObjectType, CollisionObject*> m_collision_list;
};
