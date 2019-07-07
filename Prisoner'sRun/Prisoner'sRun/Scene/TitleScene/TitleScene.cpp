#include"../TitleScene/TitleScene.h"
#include"../../Library/Draw/Draw.h"


Title::Title() {
	
	m_scene = SceneId::TITLE;
	m_scene_step = SceneStep::SCENE_INIT;
};

void Title::Init() {

	m_texture = rec.GetTextureName(TextureList::TITLE_TEX);
	m_scene_step = SceneStep::SCENE_UPDATE;
}

void Title::Update() {

	/*
	何かキーが入力されたら遷移する
	*/
	if(key.Press(VK_SPACE)) {          

		m_scene_step = SceneStep::SCENE_END;
		m_new_scene = SceneId::SCENE_QUIT;
	}
}

void Title::Draw() {

	Draw2D::Box(m_texture.c_str(), D3DXVECTOR2(0, 0));
}
