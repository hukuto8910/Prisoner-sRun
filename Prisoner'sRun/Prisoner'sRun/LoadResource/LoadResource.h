#pragma once

#include<unordered_map>
#include<string>


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
・画像名の登録

*/
class Resource {
public:
	// シングルトン
	static Resource& GetInsutance() {
		static Resource s_resource;
		return s_resource;
	}

	// 画像名の読み込み関数
	void Load();
	// リストの解放関数
	void Relese();

	std::string GetTextureName(TextureList tex) {
		auto tex_list = m_texture_list.find(tex);
		return tex_list->second;
	}

private:
	Resource() {}
	~Resource() {}
	std::unordered_map<TextureList, std::string> m_texture_list;
};
