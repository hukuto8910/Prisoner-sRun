#pragma once

#include<unordered_map>
#include"SceneBase.h"
#include"TitleScene/TitleScene.h"


class SceneManager {
public:
	// シングルトン
	static SceneManager& GetInstance() {
		static SceneManager s_sm;
		return s_sm;
	}


	void Init() {

		// 各シーンの登録
		m_scene_list.emplace(SceneId::TITLE, new Title);

		m_scene_id = SceneId::TITLE;
		m_scene = m_scene_list[m_scene_id];

		m_is_quit = false;
	}

	void Update() {

		// 現在のシーンと受け取ったシーンのIDを比較・更新する
		ChackScene(m_new_scene_id);
		// 各シーンの現在のステップを実行
		m_new_scene_id = m_scene->Control();
	}

	void Draw() {
		m_scene->Draw();
	}

	bool IsQuit() {
		return m_is_quit;
	}

private:
	SceneManager() {}
	~SceneManager() {
		for (auto scene : m_scene_list) {

			if (&scene != nullptr) {
				delete scene.second;
			}
		}
	}
	
	// 現在と新しいシーンIDを比較・更新する　引数にはm_scene_idを入れること
	void ChackScene(const SceneId new_id) {

		if (m_scene_id == new_id) {
			return;
		}
		// 終了処理が呼ばれた場合はフラグをtrueにする
		else if (new_id == SceneId::SCENE_QUIT) {
			m_is_quit = true;
			return;
		}

		// 現在のシーンと違う場合、idとシーンを新しいものに更新する
		m_scene_id = new_id;
		m_scene = m_scene_list.find(m_scene_id)->second;
	}

	bool m_is_quit;			// ゲームの終了フラグ
	std::unordered_map<SceneId, SceneBase*> m_scene_list;	// シーン格納リスト

	SceneBase* m_scene;		// 現在のシーン
	SceneId m_scene_id;		// 現在のシーンのID
	SceneId m_new_scene_id;	// 新しいシーンのID
};
