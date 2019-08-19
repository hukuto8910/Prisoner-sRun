#pragma once

#include"../SceneBase.h"
#include"../../Map/Map.h"
#include"../../Player/Player.h"
#include"../../Enemy/Enemy.h"
#include"../../Collision/CollisionManager.h"


class GameMain :public SceneBase{
public:
	GameMain();
	~GameMain()override {}

	void Init()override;
	void Update()override;
	void Draw()override;
private:
	Map* m_map;
	Player m_player;
	Enemy m_enemy;
	CollisionManager* m_collision_manager;
};
