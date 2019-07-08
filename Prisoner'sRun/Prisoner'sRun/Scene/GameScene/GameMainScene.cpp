#include"GameMeinScene.h"


GameMain::GameMain() {

	m_scene = SceneId::GAME_MAIN;
	m_scene_step = SceneStep::SCENE_INIT;
}

void GameMain::Init() {
	m_scene_step = SceneStep::SCENE_UPDATE;

}

void GameMain::Update() {
	/*
	ゲーム内の処理
	Managerクラス作ってそれを回す
	*/
}

void GameMain::Draw() {

}