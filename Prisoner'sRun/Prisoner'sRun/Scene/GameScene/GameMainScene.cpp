#include"GameMeinScene.h"



GameMain::GameMain() {
	
	m_scene = SceneId::GAME_MAIN;
	m_scene_step = SceneStep::SCENE_INIT;
}

void GameMain::Init() {

	m_player.Init();
	m_enemy.Init();
	m_collision_manager = CollisionManager::GetInstance();
	m_collision_manager->Entry(&m_player);
	m_collision_manager->Entry(&m_enemy);

	// 次シーン指定変数を現在のシーンで初期化
	m_new_scene = m_scene;

	// ステップをUpdateに移行
	m_scene_step = SceneStep::SCENE_UPDATE;
}

void GameMain::Update() {

	/*
	ゲーム内の処理
	Managerクラス作ってそれを回す
	*/

	m_player.Update();
	m_enemy.Update();
	m_map.Create();
	m_collision_manager->Update();

	// デバック用
	if (key.Press(VK_F1)) {

		m_scene_step = SceneStep::SCENE_END;
		m_new_scene = SceneId::RESULT;
	}
}

void GameMain::Draw() {
	m_player.Draw();
	m_enemy.Draw();
	m_map.Draw();
}
