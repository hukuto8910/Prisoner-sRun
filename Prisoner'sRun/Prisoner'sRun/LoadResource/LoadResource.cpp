#include"LoadResource.h"


void Resource::Load() {

	//	タイトル画面の画像登録	//
	m_texture_list.emplace(TextureList::TITLE_TEX, "Resource/Texture/Title/title.png");

	//	マップの画像登録　//
	m_texture_list.emplace(TextureList::MAP_FLOOR1_TEX, "Resource/Texture/Map/floor1.png");
	m_texture_list.emplace(TextureList::MAP_FLOOR2_TEX, "Resource/Texture/Map/floor2.png");
	m_texture_list.emplace(TextureList::MAP_FLOOR3_TEX, "Resource/Texture/Map/floor3.png");

	//　プレイヤー　//
	// ノーマル　//
	m_texture_list.emplace(TextureList::PLAYER_NORMAL_FRONT_TEX, "Resource/Texture/Player/player_front.png");
	m_texture_list.emplace(TextureList::PLAYER_NORMAL_BACK_TEX, "Resource/Texture/Player/player_back.png");
	m_texture_list.emplace(TextureList::PLAYER_NORMAL_LEFT_TEX, "Resource/Texture/Player/player_left.png");
	m_texture_list.emplace(TextureList::PLAYER_NORMAL_RIGHT_TEX, "Resource/Texture/Player/player_right.png");

	//　敵　//
	m_texture_list.emplace(TextureList::ENEMY_FRONT_TEX, "Resource/Texture/Enemy/enemy_front.png");
	m_texture_list.emplace(TextureList::ENEMY_BACK_TEX, "Resource/Texture/Enemy/enemy_back.png");
	m_texture_list.emplace(TextureList::ENEMY_LEFT_TEX, "Resource/Texture/Enemy/enemy_left.png");
	m_texture_list.emplace(TextureList::ENEMT_RIGHT_TEX, "Resource/Texture/Enemy/enemy_right.png");

	//	リザルト画面の画像登録	//
	m_texture_list.emplace(TextureList::RESULT_CLEAR_TEX, "Resource/Texture/Result/result_clear.png");
	m_texture_list.emplace(TextureList::RESULT_GAMEOVER_TEX, "Resource/Texture/Result/result_gameover.png");
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

std::string Resource::GetTextureName(TextureList texId) {

	// 指定されたTextureListのidに登録された画像を検索して画像名を返す
	auto tex = m_texture_list.find(texId);

	if (&tex == nullptr) {
		return nullptr;
	}

	return tex->second;
}
