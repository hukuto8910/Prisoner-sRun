#pragma once

#include<string>
#include<vector>
#include <fstream>
#include"../Library/Draw/Draw.h"
#include"../LoadResource/LoadResource.h"


#define MAP_CHIP_SIZE 32
#define MAP_SIZE_WIDTH 10
#define MAP_SIZE_HEIGHT 3

/*
これいる？
・Mapクラスで定義
・構造体にするにしても、クラス内で
・座標、画像、チップ番号、当たり判定の矩形が必要
*/


/*
・Dataはcsvで読み取るようにする
・縦はフル、横はUIを置くので、その分の幅で作成
・アイテムはランダム、床などの構造は基本一定
*/


class Map {
public:
	Map() {}
	~Map() {};

	void Init();
	void Update();
	void Draw();
	void Create();

private:
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
		CEILING1,
		CEILING2,
		CEILING3,
		//  天井角　//
		CEILING_CORNER1,
		CEILING_CORNER2,

		MAP_TEXTURE_MAX
	};


	// マップチップ情報
	struct MapChip {
		std::string tex;	// 画像
		D3DXVECTOR2 pos;	// 描画座標
		int id;				// マップチップ番号
	};


	// マップ画像登録関数
	std::string EntryMapTexture(const int id);
	//std::string EntryWallTexture(const int id);
	//std::string EntryCeilingTexture(const int id);
	
	// CSVファイル読み取り関数
	void LoadCsv(const std::string &file_name) {
		const char *csv_file = file_name.c_str();
		//	//FILE* file;
		//	// ファイル読み取り
			//fopen_s(&file, csv_file, "r");
		std::ifstream file;
		file.open(csv_file);
		//if (file == nullptr) {
		//	return;
		//}
		if (!file) {
			return;
		}

		//int heigjt = 0, width = 0;
		std::string str;
		int p;
		while (std::getline(file, str)) {
			if ((p = str.find("\0")) != str.npos) {
				continue;
			}
			std::vector<std::string> inner;
			while ((p = str.find(",")) != str.npos) {
				inner.push_back(str.substr(0, p));
			}
			inner.push_back(str);
			map.push_back(inner);
		}
		file.close();
	}

private:
	MapChip m_map_chip[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];	// マップチップのリスト
	int map_chipdate[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
	std::vector<std::vector<std::string>> map;
	
	Resource& res = Resource::GetInstance();
};
