#include"../TitleScene/TitleScene.h"
#include"../../Library/Draw/Draw.h"


Title::Title() {
	m_texture = rec.GetTextureName(TextureList::TITLE_TEX);
};

void Title::Update() {
	/*
	何かキーが入力されたら遷移する
	*/
}

void Title::Draw() {

	Draw2D::Box(m_texture.c_str(), D3DXVECTOR2(0, 0));
}
