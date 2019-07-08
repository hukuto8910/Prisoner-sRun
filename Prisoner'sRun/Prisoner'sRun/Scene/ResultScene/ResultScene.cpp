#include"ResultScene.h"
#include"../../Library/Draw/Draw.h"


Result::Result() {

	m_scene = SceneId::RESULT;
	m_scene_step = SceneStep::SCENE_INIT;
}

void Result::Init() {

	// 次シーン指定変数を現在のシーンで初期化
	m_new_scene = m_scene;

	/*
	フラグによってテクスチャを変える
	if(クリアフラグ == true){
		m_texture = res.GetTextureName(TextureList::RESULT_CLEAR_TEX);
	}
	else if(ゲームオーバーフラグ == true){
		m_texture = res.GetTextureName(TextureList::RESULT_GAMEOVER_TEX);
	*/
	// 《仮でクリア画面の描画》
	m_texture = res.GetTextureName(TextureList::RESULT_CLEAR_TEX);

	// ステップをUpdateに移行
	m_scene_step = SceneStep::SCENE_UPDATE;
}

void Result::Update() {

	/*
	BadEndとHappyEndがあるので、
	フラグでクリアリザルトとゲームオーバーリザルトを変える
	（変更するのはサウンドとテクスチャのみで遷移、描画方法は同一）
	*/

	// デバック用
	if (key.Press(VK_F1)) {

		m_scene_step = SceneStep::SCENE_END;
		m_new_scene = SceneId::TITLE;
	}
}

void Result::Draw() {

	Draw2D::Box(m_texture.c_str(), D3DXVECTOR2(0, 0));
	if (m_scene != m_new_scene) {
		tex.Relese();
	}
}
