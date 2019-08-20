#include<sstream>
#include"Map.h"


Map::Map() {

	// 容量を予約
	m_chip_list.reserve(30);

	// CSV読み取り
	if (InputCSV("Map/MapChipData/mapdata.csv", m_chip_list) == false) {
		MessageBox(NULL, "CSV読み込み失敗", "", MB_OK);
	}
} 

void Map::Init() {

	// チープデータの設定
	for (int i = 0; i < MAP_SIZE_HEIGHT; i++) {
		for (int j = 0; j < MAP_SIZE_WIDTH; j++) {

			// チップ番号の設定
			map[i][j].chip_num = std::stoi(m_chip_list[i][j]);

		}
	}
}

bool Map::InputCSV(const std::string &file_name,
	std::vector<std::vector<std::string>> &list) {

	const char* csv_file = file_name.c_str();
	std::ifstream file;
	// CSVファイルをオープン
	file.open(csv_file);
	if (!file) {
		return false;
	}

	// 1行分読み取り用の文字列
	std::string line;
	// 読み取り位置の指定用
	int str_num;
	// 1行分読み取り用配列
	std::vector<std::string> str_list;
	// 配列の容量を予約
	str_list.reserve(60);

	// 1行を読み取る
	while (std::getline(file, line)) {
		
		// コンマまでの文字を読み取って、配列に代入
		while ((str_num = line.find(",")) != line.npos) {

			str_list.emplace_back(line.substr(0, str_num));
			line = line.substr(str_num + 1);
		}
		
		// 最後の1文字を代入
		str_list.emplace_back(line);
		// 読み込んだ1行を配列に追加しなおす
		list.emplace_back(str_list);

		// 1行分読み取り用の配列をクリア
		str_list.clear();
	}

	// ファイルのクローズ
	file.close();

	return true;
}
/*
void Map::EntryMapTexture(MapChip& map) {

	switch (map.chip_num) {

	case MapChipList::MAP_TEXTURE_INIT:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER1_TEX);
		break;

	case MapChipList::FLOOR1:
		map.tex_name = res.GetTextureName(TextureList::MAP_FLOOR1_TEX);
		break;

	case MapChipList::FLOOR2:
		map.tex_name = res.GetTextureName(TextureList::MAP_FLOOR2_TEX);
		break;

	case MapChipList::FLOOR3:
		map.tex_name = res.GetTextureName(TextureList::MAP_FLOOR3_TEX);
		break;

	case MapChipList::WALL_TOP1:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_TOP1_TEX);
		break;

	case MapChipList::WALL_TOP2:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_TOP2_TEX);
		break;

	case MapChipList::WALL_TOP3:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_TOP3_TEX);
		break;

	case MapChipList::WALL_UNDER1:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER1_TEX);
		break;

	case MapChipList::WALL_UNDER2:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER2_TEX);
		break;

	case MapChipList::WALL_UNDER3:
		map.tex_name = res.GetTextureName(TextureList::MAP_WALL_UNDER3_TEX);
		break;

	case MapChipList::CEILING_RIGTH1:
	case MapChipList::CEILING_LEFT1:
	case MapChipList::CEILING_UNDER1:
	case MapChipList::CEILING_TOP1:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING1_TEX);
		break;

	case MapChipList::CEILING_RIGTH2:
	case MapChipList::CEILING_LEFT2:
	case MapChipList::CEILING_UNDER2:
	case MapChipList::CEILING_TOP2:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING2_TEX);
		break;

	case MapChipList::CEILING_RIGTH3:
	case MapChipList::CEILING_LEFT3:
	case MapChipList::CEILING_UNDER3:
	case MapChipList::CEILING_TOP3:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING3_TEX);
		break;

	case MapChipList::CEILING_CORNER_TOP_LEFT:	
	case MapChipList::CEILING_CORNER_TOP_RIGHT:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING_CORNER1_TEX);
		break;

	case MapChipList::CEILING_CORNER_UNDER_LEFT:
	case MapChipList::CEILING_CORNER_UNDER_RIGHT:
		map.tex_name = res.GetTextureName(TextureList::MAP_CEILING_CORNER2_TEX);
		break;
	}

	return;
}*/
