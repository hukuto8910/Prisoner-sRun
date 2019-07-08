#pragma once

#include"../Library/Input/Keyboard.h"
#include"../../LoadResource/LoadResource.h"


// シーン指定用ID
enum SceneId {
	TITLE,
	GAME_MAIN,
	RESULT,
	SCENE_QUIT
};


// シーンの基底クラス
class SceneBase {
public:
	// シーン内の処理ステップ
	enum SceneStep {
		SCENE_INIT,
		SCENE_UPDATE,
		SCENE_END
	};


	/*
	各シーンのコンストラクタでは、自身のSceneIdと最初のSceneStepを指定すること
	*/
	SceneBase() {}
	virtual ~SceneBase() {}


	// 初期化～終了処理まで必ず各派生先のシーン内で定義すること
	/*
	Init	:シーン遷移時に毎回行う初期化
	Update	:シーン内の更新
	Draw	:各シーンの描画
	*/
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;


	SceneId End() {
		m_scene_step = SceneStep::SCENE_INIT;
		return m_new_scene;
	}


	// シーンの順路管理
	/*
	基本的に初期化→更新→終了処理の順
	終了処理以外は自身のシーンを返し、終了処理は次のシーンを返す
	*/
	SceneId Control() {

		switch (m_scene_step) {

		case SceneStep::SCENE_INIT:
			Init();
			break;
		case SceneStep::SCENE_UPDATE:
			Update();
			break;
		case SceneStep::SCENE_END:
			return End();
		}
		
		return m_scene;
	}


protected:
	SceneStep m_scene_step;	// シーン内の順
	SceneId m_scene;		// 現在のシーン
	SceneId m_new_scene;	// 次のシーン

	Key& key = Key::GetInstance();			// キーボード
	Resource& rec = Resource::GetInstance();// 画像ソース
};
