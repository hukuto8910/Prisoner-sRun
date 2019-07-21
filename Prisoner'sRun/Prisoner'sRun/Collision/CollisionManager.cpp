#include"Collision/CollisionManager.h"


void CollisionManager::Update() {

	// プレイヤーと敵の衝突判定
	CheckHitObject(m_collision_list[Collision::CollisionObjectType::PLAYER], m_collision_list[Collision::CollisionObjectType::ENEMY]);
}

// 衝突判定のチェック
void CollisionManager::CheckHitObject(CollisionObject* obj1,CollisionObject* obj2) {

	if (obj1 == nullptr || obj2 == nullptr) {
		return;
	}

	// オブジェクトの衝突形状を取得
	Collision::ColliderType object1 = obj1->GetColliderType();
	Collision::ColliderType object2 = obj2->GetColliderType();

	// 衝突判定の種類別で処理
	switch (object1) {

	case Collision::ColliderType::RECT:
		CollisionRectAndRect(obj1, obj2);
		break;
	}
}

// 矩形同士の衝突
void CollisionManager::CollisionRectAndRect(CollisionObject* obj1, CollisionObject* obj2) {

	Collision::RectCollider rect1;
	Collision::RectCollider rect2;

	// 判定形状の情報を取得
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
