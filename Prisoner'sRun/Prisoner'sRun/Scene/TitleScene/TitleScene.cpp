#include"../TitleScene/TitleScene.h"
#include"../../Library/Draw/Draw.h"


Title::Title() {
	
	m_scene = SceneId::TITLE;
	m_scene_step = SceneStep::SCENE_INIT;
};

void Title::Init() {

	// 次シーン指定変数を現在のシーンで初期化
	m_new_scene = m_scene;

	// 画像名の受取
	m_texture = res.GetTextureName(TextureList::TITLE_TEX);
	
	// ステップをUpdateに移行
	m_scene_step = SceneStep::SCENE_UPDATE;
}

void Title::Update() {

	/*
	何かキーが入力されたら遷移する
	*/

	// キーは未定
	if(key.Press(VK_SPACE)) {          

		m_scene_step = SceneStep::SCENE_END;
		m_new_scene = SceneId::GAME_MAIN;
	}
}

void Title::Draw() {

	Draw2D::Box(m_texture.c_str(), D3DXVECTOR2(0, 0));
	
	if (m_scene != m_new_scene) {
		tex.Relese();
	}
}
