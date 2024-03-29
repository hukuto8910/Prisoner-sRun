﻿#pragma once

#include<unordered_map>
#include<string>


// 画像を指定するための名前リスト
enum TextureList {

	//  タイトル　//
	TITLE_TEX,

	//　シナリオ　//

	//  マップチップ　//
	//　床　//
	MAP_FLOOR1_TEX,
	MAP_FLOOR2_TEX,
	MAP_FLOOR3_TEX,
	// 壁　//
	MAP_WALL_TOP1_TEX,
	MAP_WALL_TOP2_TEX,
	MAP_WALL_TOP3_TEX,
	MAP_WALL_UNDER1_TEX,
	MAP_WALL_UNDER2_TEX,
	MAP_WALL_UNDER3_TEX,
	// 天井　//
	MAP_CEILING1_TEX,
	MAP_CEILING2_TEX,
	MAP_CEILING3_TEX,
	MAP_CEILING_CORNER1_TEX,
	MAP_CEILING_CORNER2_TEX,

	//　キャラクター　//
	// プレイヤー　//
	PLAYER_NORMAL_FRONT_TEX,
	PLAYER_NORMAL_BACK_TEX,
	PLAYER_NORMAL_LEFT_TEX,
	PLAYER_NORMAL_RIGHT_TEX,
	// エネミー　//
	ENEMY_FRONT_TEX,
	ENEMY_BACK_TEX,
	ENEMY_LEFT_TEX,
	ENEMT_RIGHT_TEX,

	//　ゲーム内UI　//


	//	リザルト　//
	RESULT_CLEAR_TEX,
	RESULT_GAMEOVER_TEX,

	TEXTURE_MAX
};


// リソースクラス
class Resource {
public:
	// シングルトン
	/*
	必要に応じて　Resoutce& res = Resource::GetInstance();
	または　	　Resource::GetInstance().Load();
	と記述して使うこと
	*/
	static Resource& GetInstance() {
		static Resource s_resource;
		return s_resource;
	}


	// 画像名の読み込み関数
	void Load();

	// リストの解放関数
	void Relese();

	// 登録されているテクスチャ名のゲッター
	/*
	使用例：res.GetTextureName(TextureList::TITLE_TEX);
	引数で上記に定義されている定数TextureListから、使用したい画像の定数名を指定する
	*/
	std::string GetTextureName(TextureList texId);

private:
	Resource() {}
	~Resource() {}

private:
	std::unordered_map<TextureList, std::string> m_texture_list; // 定数名と画像名のリスト
};
