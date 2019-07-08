#include"LoadResource.h"


void Resource::Load() {

	//	タイトル画面の画像登録	//
	m_texture_list.emplace(TextureList::TITLE_TEX, "Resource/Texture/Title/title.png");

	//	マップの画像登録　//
	m_texture_list.emplace(TextureList::MAP_FLOOR1, "Resource/Texture/Map/floor1.png");
	m_texture_list.emplace(TextureList::MAP_FLOOR2, "Resource/Texture/Map/floor2.png");
	m_texture_list.emplace(TextureList::MAP_FLOOR3, "Resource/Texture/Map/floor3.png");

	//	リザルト画面の画像登録	//
	m_texture_list.emplace(TextureList::RESULT_CLEAR_TEX, "Resource/Texture/Result/result_clear.png");
	m_texture_list.emplace(TextureList::RESULT_CLEAR_TEX, "Resource/Texture/Result/result_gameover.png");
}

void Resource::Relese() {

	for (auto texture_list = m_texture_list.begin(); texture_list != m_texture_list.end();) {

		if (&texture_list != nullptr) {
			//delete &texture_list;
			texture_list = m_texture_list.erase(texture_list);
		}
		else {
			texture_list++;
		}
	}
}

std::string Resource::GetTextureName(TextureList tex_id) {

	// 指定されたTextureListのidに登録された画像を検索して画像名を返す
	auto tex = m_texture_list.find(tex_id);

	if (&tex == nullptr) {
		return nullptr;
	}

	return tex->second;
}
