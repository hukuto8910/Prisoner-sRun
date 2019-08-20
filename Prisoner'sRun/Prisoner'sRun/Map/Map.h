#pragma once

#include<string>
#include<vector>
#include"../Library/Draw/Draw.h"
#include"../LoadResource/LoadResource.h"


// ピクセルサイズ
const int MAP_CHIP_SIZE = 32;
// マップの横サイズ
const int MAP_SIZE_WIDTH = 60;
// マップの縦サイズ
const int MAP_SIZE_HEIGHT = 33;


class Map {
public:
	Map();
	~Map() {}

	void Init();
	void Draw();

private:
	// マップチップの構造体
	struct MapChip {
		//MapChip() :chip_num(0), tex_name(nullptr), pos(0, 0) {}
		int chip_num;			// チップ番号
		std::string tex_name;	// テクスチャ―名
		D3DXVECTOR2 pos;		// 描画位置
	};

	// CSV読み込み関数　
	/*
	第1：読み込みたいCSVファイル名
	第2：書き込み用の文字列ファイル
	*/
	bool InputCSV(const std::string &fileName,
		std::vector<std::vector<std::string>> &list);

	// 画像登録関数
	/*
	引数：配列の要素(MapChipオブジェクト)
	*/
	void EntryMapTexture(MapChip& map);
private:
	// 仮リスト
	//std::vector<std::vector<MapChip*>>m_map;
	// CSV読み込み用リスト
	std::vector<std::vector<std::string>> m_chip_list;
	// マップチップリスト
	MapChip m_map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];

	Resource& res = Resource::GetInstance();


	// 画像指定用リスト
	enum MapChipList {
		MAP_TEXTURE_INIT,
		//  床  //
		FLOOR1,
		FLOOR2,
		FLOOR3,
		//　上壁　//
		WALL_TOP1,
		WALL_TOP2,
		WALL_TOP3,
		//　下壁　//
		WALL_UNDER1,
		WALL_UNDER2,
		WALL_UNDER3,
		//　天井　//
		// 天井画像の180度回転
		CEILING_TOP1,
		CEILING_TOP2,
		CEILING_TOP3,
		// 天井画像の通常
		CEILING_UNDER1,
		CEILING_UNDER2,
		CEILING_UNDER3,
		// 天井画像の270度回転
		CEILING_LEFT1,
		CEILING_LEFT2,
		CEILING_LEFT3,
		// 天井画像の90度回転
		CEILING_RIGTH1,
		CEILING_RIGTH2,
		CEILING_RIGTH3,
		//  天井角　//
		CEILING_CORNER_TOP_LEFT,	// 左上の角
		CEILING_CORNER_TOP_RIGHT,	// 上角の反転描画
		CEILING_CORNER_UNDER_RIGHT, // 右下の角
		CEILING_CORNER_UNDER_LEFT,	// 下角の反転描画

		MAP_TEXTURE_MAX
	};
};
	
