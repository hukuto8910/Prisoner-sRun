#pragma once


#include<unordered_map>
#include<string>
#include"../Library/Texture/Texture.h"


// 画像のリスト
enum TextureList {

	//  タイトル画像　//
	TITLE_TEX,

	//  マップチップ　//
	MAP_FLOOR1,
	MAP_FLOOR2,
	MAP_FLOOR3,
	TEXTURE_MAX
};

/*
・すべての画像をまとめて読み込み保存
・指定するだけで画像を呼び出せるように
・enumと合わせる
*/
namespace Resource {

	//Texture m_texture_list[TextureList::TEXTURE_MAX];
	std::unordered_map<TextureList, Texture>m_texture_list[TextureList::TEXTURE_MAX];

	void Load() {
		// タイトル画面の画像登録
		m_texture_list->emplace(TextureList::TITLE_TEX, "Resource/Texture/Title/title.png");

		// マップの画像登録
		//m_texture_list[TextureList::MAP_FLOOR1] = "Resource/Texture/Map/floor1.png";
		//m_texture_list[TextureList::MAP_FLOOR2] = "Resource/Texture/Map/floor2.png";
		//m_texture_list[TextureList::MAP_FLOOR3] = "Resource/Texture/Map/floor3.png";
		m_texture_list->emplace(TextureList::MAP_FLOOR1, "Resource/Texture/Map/floor1.png");
		m_texture_list->emplace(TextureList::MAP_FLOOR2, "Resource/Texture/Map/floor2.png");
		m_texture_list->emplace(TextureList::MAP_FLOOR3, "Resource/Texture/Map/floor3.png");
	}

	void Relese() {
		for (auto texture_list = m_texture_list->begin(); texture_list != m_texture_list->end();) {
			if (&texture_list != nullptr) {
				//delete &texture_list;
				texture_list = m_texture_list->erase(texture_list);
			}
			else {
				texture_list++;
			}
		}
	}
}
