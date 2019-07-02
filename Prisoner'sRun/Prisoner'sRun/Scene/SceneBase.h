#pragma once

#include"../Library/Input/Keyboard.h"


enum SceneId {
	TITLE,
	GAME_MAIN,
	CLEAR_RESULT,
	GAMEOVER_RESULT,
	SCENE_QUIT,
	SCENEID_MAX
};

class SceneBase {
public:
	enum SceneStep {
		SCENE_INIT,
		SCENE_UPDATE,
		SCENE_END
	};


	~SceneBase() {}

	// 初期化～終了処理まで必ず各派生先のシーン内で定義すること
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual SceneId End() = 0;

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

	Key& key = Key::GetInstance();

private:
	SceneBase() {}
};