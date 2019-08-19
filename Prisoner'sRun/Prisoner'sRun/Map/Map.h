#pragma once

#include<string>
#include<vector>
#include <fstream>
#include"../Library/Draw/Draw.h"
#include"../LoadResource/LoadResource.h"


const int MAP_CHIP_SIZE = 32;
const int MAP_SIZE_WIDTH = 60;
const int MAP_SIZE_HEIGHT = 33;

struct MapChip {
	MapChip() :chip_num(0), tex_name(nullptr), pos(0, 0) {}
	int chip_num;
	std::string tex_name;
	D3DXVECTOR2 pos;
};

class Map {
public:
	Map();
	~Map() {}

	void Init();

private:
	std::vector<std::vector<MapChip*>>m_map;
	MapChip* map[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH];
};
	//// 画像指定用リスト
	//enum MapChipList {
	//	MAP_TEXTURE_INIT,
	//	//  床  //
	//	FLOOR1,
	//	FLOOR2,
	//	FLOOR3,
	//	//　上壁　//
	//	WALL_TOP1,
	//	WALL_TOP2,
	//	WALL_TOP3,
	//	//　下壁　//
	//	WALL_UNDER1,
	//	WALL_UNDER2,
	//	WALL_UNDER3,
	//	//　天井　//
	//	// 天井画像の180度回転
	//	CEILING_TOP1,
	//	CEILING_TOP2,
	//	CEILING_TOP3,
	//	// 天井画像の通常
	//	CEILING_UNDER1,
	//	CEILING_UNDER2,
	//	CEILING_UNDER3,
	//	// 天井画像の270度回転
	//	CEILING_LEFT1,
	//	CEILING_LEFT2,
	//	CEILING_LEFT3,
	//	// 天井画像の90度回転
	//	CEILING_RIGTH1,
	//	CEILING_RIGTH2,
	//	CEILING_RIGTH3,
	//	//  天井角　//
	//	CEILING_CORNER_TOP_LEFT,	// 左上の角
	//	CEILING_CORNER_TOP_RIGHT,	// 上角の反転描画
	//	CEILING_CORNER_UNDER_RIGHT, // 右下の角
	//	CEILING_CORNER_UNDER_LEFT,	// 下角の反転描画

	//	MAP_TEXTURE_MAX
	//};

/*
// CSVファイル読み取り(C++)
void LoadCsv(const std::string &file_name) {

	// ファイル登録
	const char *csv_file = file_name.c_str();
	std::ifstream file;
	// 登録したcsvファイルの開ける
	file.open(csv_file);
	if (!file) {
		return;
	}

	std::string line;
	int p;

	// 1行づつ読み込んでいく
	while (std::getline(file, line)) {

		std::vector<std::string> inner;
		inner.reserve(60);

		// コンマで区切られるまで文字を読み込む
		while ((p = line.find(",")) != line.npos) {
			inner.emplace_back(line.substr(0, p));
			// 次の文字まで飛ばす
			line = line.substr(p + 1);
		}

		// 最後の文字を追加
		inner.emplace_back(line);
		// 専用の変数に1行を代入
		m_map.emplace_back(inner);


		//unsigned int i = 0;
		//unsigned int j = 0;
		//for (auto list = inner.begin(); list != inner.end();) {
		//	m_map_chip[i][j].id = std::atoi(list[j].c_str());
		//	j++;
		//}
		//i++;
	}

	// ファイルを閉じる
	file.close();
}

// ファイル読み込み(C言語)
void InputCSV(const std::string &fileName, std::vector<std::vector<std::string>>& list) {
	FILE* file = nullptr;
	char buf[256];
	int read_line = 0;

	fopen_s(&file, fileName.c_str(), "r");
	if (file == nullptr) {
		return;
	}

	std::vector<std::string> temp;
	char str[256];
	while (fgets(buf, 256, file) != nullptr) {
		if (++read_line <= 0) {
			continue;
		}
		else if (read_line > MAP_SIZE_HEIGHT) {
			break;
		}
		fscanf_s(file, "%[^,]", str);

	}
}
*/
